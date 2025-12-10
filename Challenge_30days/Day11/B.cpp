#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> degree(n + 1, 0), topo; 
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) if (degree[i] == 0){
        q.push(i);
    }

    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto v : g[u]){
            degree[v]--;
            if(degree[v] == 0){
                q.push(v);
            }
        }
    }

    vector<int> dp(n + 1, -1e9), parent(n + 1, -1);
    dp[1] = 1;
    
    for (auto u : topo){
        if (dp[u] < 0) continue;
        for(auto v : g[u]){
            if (dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == -1e9){
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> path;
        path.push_back(n);
        int v = parent[n];
        while (v != 1) {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(1);
        reverse(all(path));

        cout << path.size() << '\n';
        for (auto x : path) cout << x << ' ';
    }

    return 0;
}