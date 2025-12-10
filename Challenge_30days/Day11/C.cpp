#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int MOD = 1e9 + 7;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int> > g(n + 1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (!indegree[i]) q.push(i);
    }

    vector<int> topo;
    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto v : g[u]){
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }

    vector<int> d(n + 1, 0);
    d[1] = 1;
    for (auto u : topo){
        for (auto v : g[u]) {
            d[v] = (d[v] + d[u]) % MOD;
        }
    }

    cout << d[n] % MOD;

    return 0;
}