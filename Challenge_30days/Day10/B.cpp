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
    }
    vector<int> d(n + 1, 0), parent(n + 1, -1);
    int x = -1;
    for(int i = 1; i <= n; i++){
        x = -1;
        for (auto e : edges){
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.w){
                d[e.b] = d[e.a] + e.w;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1){
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            x = parent[x];
        }
        vector<int> cycle;
        int v = parent[x];
        cycle.push_back(x);
        while (v != x){
            cycle.push_back(v);
            v = parent[v];
        }
        cycle.push_back(x);
        reverse(all(cycle));
        for (auto u : cycle) cout << u << ' ';
    }
    
    return 0;
}