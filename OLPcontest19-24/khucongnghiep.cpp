#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

const int MOD = 998244353;

struct matrix {
    int a[2][2];
};

int nhan(int a, int b) {
    int res = 0;
    while(b){
        if (b & 1) res = res + a % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

matrix nhanmatrix(matrix a, matrix b){
    matrix c;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            c.a[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.a[i][j] = (c.a[i][j] + nhan(a.a[i][k], b.a[k][j]) % MOD) % MOD; 
        }
    }
    return c;
}

matrix mu(matrix a, int n){
    if (n == 1) return a;
    matrix res = mu(a, n / 2);
    if (n & 1) return nhanmatrix(nhanmatrix(res, res),a);
    return nhanmatrix(res, res);
}

int fibo(int n){
    matrix base;
    base.a[0][0] = 1; base.a[0][1] = 1;
    base.a[1][0] = 1; base.a[1][1] = 0;

    matrix res = mu(base, n - 1);
    return res.a[0][0] % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    if (n <= 1){
        cout << n + 1;
        return 0;
    }
    
    cout << nhan(fibo(n+1), fibo(n + 2)) % MOD;
    return 0;
}

/*
0 1
1 2
2 6
3 15
4 40 

*/