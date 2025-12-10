#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, q; cin >> n >> m >> q;

    vector<vector<pii>> g(n + 1);
    while (m--){
        int u, v, t; cin >> u >> v >> t;
        g[u].push_back({v, t});
    }

    vector<vector<int>> d(2, vector<int>(n + 1, 1e18));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> qq;
    qq.push({0, 1, 0});
    d[0][1] = 0;
    while (qq.size()){
        auto [du, u, used] = qq.top(); qq.pop();
        if (du != d[used][u]) continue;
        for (auto [v, w]: g[u]){
            if (d[used][v] > d[used][u] + w){
                d[used][v] = d[used][u] + w;
                qq.push({d[used][v], v, used});
            }
            if (!used && d[1][v] > d[used][u]){
                d[1][v] = d[used][u];
                qq.push({d[1][v], v, 1});
            }
        }
    } 

    while(q--){
        int s, t; cin >> s >> t;
        cout << min(d[1][s] + t, d[0][s]) << '\n';
    }
    

    return 0;
}

/*
4 4 3  
1 2 6  
2 4 10  
1 3 16  
3 4 4  
3 14  
4 14  
4 11
*/