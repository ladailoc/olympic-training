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
 
    vector<vector<int>> d(n + 1, vector<int>(2, LLONG_MAX));
    d[1][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({0, 1, 0}); // dist, node, used
    while (q.size()){
        auto [du, u, used] = q.top(); q.pop();
        if (du != d[u][used]) continue;
        for (auto [v, w] : g[u]){
            if (d[v][used] > d[u][used] + w){
                d[v][used] = d[u][used] + w;
                q.push({d[v][used], v, used});
            }
            if (!used && d[v][1] > d[u][used] + w / 2){
                d[v][1] = d[u][used] + w / 2;
                q.push({d[v][1], v, 1});
            }
        }
    }
    cout << d[n][1];
    return 0;
}