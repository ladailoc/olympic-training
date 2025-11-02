#include <bits/stdc++.h>    
using namespace std;

#define int long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define f first
#define s second
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > v(n + 2, vector<char>(m + 2));

    pii start, end;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
            if (v[i][j] == 'A') start = {i, j};
            if (v[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<int>> d(n + 1, vector<int>(m + 1, 1e18));
    vector<vector<pii>> parent(n + 1, vector<pii> (m + 1));
    queue<pii> q; 
    q.push({start.f, start.s});
    d[start.f][start.s] = 0;

    while (q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && v[xx][yy] != '#'){
                if (d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    parent[xx][yy] = {x, y};
                    q.push({xx, yy});
                }
            }
        }
    }

    if (d[end.f][end.s] == 1e18) {
        cout << "NO";
    }
    else {
        cout << "YES\n" << d[end.f][end.s] << '\n';
        pii par = parent[end.f][end.s];
        vector<string> path;
        while (start.f != end.f || start.s != end.s){
            if (par.f == end.f) {
                if (par.s > end.s){
                    path.push_back("L");
                }
                else path.push_back("R");
                end.s = par.s;
            }
            else {
                if (par.f > end.f) {
                    path.push_back("U");
                }
                else path.push_back("D");
                end.f = par.f;
            }
            par = parent[par.f][par.s];
        }
        
        reverse(all(path));
        for (auto x: path) cout << x;
    }



    return 0;

}