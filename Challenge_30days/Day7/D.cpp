#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
int n, m; 
vector<int> team;
vector<vector<int>> g;

bool dfs(int x, int cur){
    team[x] = cur;
    for(auto v : g[x]){
        if (team[v] == 0) {
            if(!dfs(v, -cur)) return false;
        }
        else if (team[v] == cur) return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    g.resize(n + 1);
    team.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cur = 1;
    for(int i = 1; i <= n; i++){
        if (team[i] == 0) {
            if (!dfs(i, cur)){
                cout << "IMPOSSIBLE";
                return 0;
            }
            cur *= -1;
        }
    }

    for (int i = 1; i <= n; i++){
        if (team[i] == 1) cout << 1 << " ";
        else cout << 2 << " ";
    }


    
    return 0;
}