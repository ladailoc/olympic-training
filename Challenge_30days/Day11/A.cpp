#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> degree(n + 1, 0);
    while (m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }
 
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }
 
    vector<int> topo;
    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto v : g[u]){
            degree[v]--;
            if (degree[v] == 0){
                q.push(v);
            }
        }
    }
 
    if (topo.size() != n) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (auto u : topo) cout << u << ' ';
    }
    
    return 0;
}