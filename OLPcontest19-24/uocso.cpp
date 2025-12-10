#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
int a, b, m;

struct matrix{
    int a[2][2];
};

int nhan(int a, int b){
    int res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

matrix nhanmt(matrix a, matrix b){
    matrix c;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            c.a[i][j] = 0;
            for (int k = 0; k < 2; k++){
                c.a[i][j] = (c.a[i][j] + nhan(a.a[i][k], b.a[k][j]) % m) % m;
            }
        }
    }
    return c;
}


matrix mu(matrix a, int n){
    if (n == 0) {
        matrix res;
        res.a[0][0] = 1; res.a[0][1] = 0;
        res.a[1][0] = 0; res.a[1][1] = 1;
        return res;
    }
    if (n == 1) return a;
    matrix tmp = mu(a, n / 2);
    if (n % 2 == 0) return nhanmt(tmp, tmp);
    return nhanmt(nhanmt(tmp, tmp), a);
}

int fib(int n) {
    if (n <= 1) return n;
    matrix base;
    base.a[0][0] = 1; base.a[0][1] = 1;
    base.a[1][0] = 1; base.a[1][1] = 0;
    matrix res = mu(base, n - 1);
    return res.a[0][0] % m;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> a >> b >> m;

    cout << fib(__gcd(a, b)) % m;

    return 0;
}

/*
6 9 10
*/