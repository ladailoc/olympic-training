#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

const int MOD = 1e9 + 7;

struct Comb{
    vector<int> fact, invfact;
    Comb(int n){
        fact.resize(n + 1, 1);
        invfact.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invfact[i] = invfact[i+1] * (i + 1) % MOD;
    }
    int modpow(int a, int n){
        int res = 1;
        while (n) {
            if (n & 1) res = res * a % MOD;
            a = a * a % MOD;
            n >>= 1;
        }
        return res;
    }
    int C(int n, int k){
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    Comb comb(1e6 + 7);
    while (t--){
        int a, b; cin >> a >> b;
        cout << comb.C(a, b) << '\n';
    }

    return 0;
}


/*

*/
