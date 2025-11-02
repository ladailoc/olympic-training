#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
const int maxn = 1e3 + 7;
vector<vector<int>> used(maxn, vector<int>(maxn, 0));
vector<vector<int>> a(maxn, vector<int>(maxn));

int n, m; 
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] && !used[xx][yy])
            dfs(xx, yy);
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        char c; cin >> c;
        if (c == '.') a[i][j] = 1;
        else a[i][j] = 0;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (!used[i][j] && a[i][j] == 1) {
        dfs(i, j);
        cnt++;
    }
    cout << cnt;

    return 0;
}