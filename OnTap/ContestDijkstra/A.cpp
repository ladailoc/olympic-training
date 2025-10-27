#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; i++){
        int a, b, x; cin >> a >> b >> x;
        g[a].push_back({b, x});
        g[b].push_back({a, x});
    }

    vector<int> d(n + 1, 1e18);
    priority_queue<pii, vector<pii>, greater<pii> > q;
    int s = 1;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty()){
        auto [du, u] = q.top(); q.pop();
        if (du > d[u]) continue;
        for (auto [v, w] : g[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        } 
    }

    for(int i = 1; i <= n; i++) cout << d[i] << ' ';

    return 0;
}