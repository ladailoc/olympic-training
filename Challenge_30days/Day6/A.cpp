#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
int pow_mod(int a, int n){
    int res = 1;
    for (; n > 0; n >>= 1, a = a * a % MOD)
        if (n & 1) res = res * a % MOD;

    return res;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    cout << pow_mod(2, n);

    return 0;
}

