#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

int n, k, x, y, s; 

struct matrix{
    int a[101][101];
};  
vector<matrix> v;

matrix nhanmatrix (const matrix &a, const matrix &b){
    matrix c = {};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            __int128 sum = 0;
            for (int k = 0; k < n; k++){
                sum = (sum + (__int128)a.a[i][k] * b.a[k][j] % s) % s;
            }
            c.a[i][j] = (int) sum;
        }
    }
    return c;
}

matrix solve(int l, int r){
    if (l == r) return v[l];
    int m = (l + r) >> 1;
    matrix left = solve(l, m);
    matrix right = solve(m + 1, r);
    return nhanmatrix(left, right);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> k >> n >> x >> y >> s;

    v.assign(k, {});    
    for (int l = 0; l < k; l++){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[l].a[i][j];
    }
    
    x--, y--;
    cout << solve(0, k - 1).a[x][y] % s ; 

    return 0;
}

/*
2 2 1 2 10 
1 2 
3 4 
5 6 
7 8 
*/