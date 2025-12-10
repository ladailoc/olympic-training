#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }
 
    vector<int> d(n + 1, LLONG_MAX);
    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (q.size()){
        auto [du, u] = q.top(); q.pop();
        if (du != d[u]) continue;
        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
 
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}