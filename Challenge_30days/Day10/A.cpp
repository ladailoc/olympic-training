#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

const int INF = 1e18;

struct Edge {
    int a, b, w;
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<Edge> edges(m);  
    for (int i = 0; i < m; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].w = -edges[i].w;
    }
    vector<int> d(n + 1, INF);
    d[1] = 0;
    for(int i = 1; i <= n - 1; i++){
        bool changed = false;
        for (auto e : edges){
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.w){
                d[e.b] = d[e.a] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    vector<int> neg(n + 1, 0);
    for(auto e : edges){
        if (d[e.a] < INF && d[e.b] > d[e.a] + e.w){
            neg[e.b] = 1;
        }
    }

    vector<vector<int>> g(n + 1);
    for(auto e : edges){
        g[e.a].push_back(e.b);
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if (neg[i]){
            q.push(i);
        }
    }
    while (q.size()){
        int u = q.front(); q.pop();
        for (auto v : g[u]){
            if (!neg[v]){
                neg[v] = 1;
                q.push(v);
            }
        }
    }
    if (neg[n]){
        cout << -1;
    }
    else {
        cout << -d[n];
    }
    
    return 0;
}