#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), used(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int mx = 0;
        for (int j = 0; j < m; j++){
            if (mx < a[i][j]){
                mx = a[i][j];
                if (!used[i][j]) ans++, used[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        int mx = 0;
        for (int j = m - 1; j >= 0; j--){
            if (mx < a[i][j]){
                mx = a[i][j];
                if (!used[i][j]) ans++, used[i][j] = 1;
            }
        }
    }
    for (int j = 0; j < m; j++){
        int mx = 0;
        for (int i = 0; i < n; i++){
            if (mx < a[i][j]){
                mx = a[i][j];
                if (!used[i][j]) ans++, used[i][j] = 1;
            }
        }
    }
    for (int j = 0; j < m; j++){
        int mx = 0;
        for (int i = n - 1; i >= 0; i--){
            if (mx < a[i][j]){
                mx = a[i][j];
                if (!used[i][j]) ans++, used[i][j] = 1;
            }
        }
    }
    cout << ans;

    return 0;
}

/*
4 4 
2 3 5 3 
2 1 2 2 
3 4 3 4 
2 1 3 3
*/