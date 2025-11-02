#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    vector<int> d(n + 1, 1e18), parent(n + 1); 
    q.push(1);
    d[1] = 0;
    parent[1] = -1;
    while (q.size()){
        auto x = q.front(); q.pop();
        for (auto v: g[x]){
            if (d[v] > d[x] + 1) {
                d[v] = d[x] + 1;
                parent[v] = x;
                q.push(v);
                if (v == n) {
                    cout << d[v] + 1 << '\n';
                    int cur = v;
                    vector<int> path;
                    while (cur != -1) {
                        path.push_back(cur);
                        cur = parent[cur];
                    }

                    reverse(all(path));
                    for(auto x: path) cout << x << " ";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}