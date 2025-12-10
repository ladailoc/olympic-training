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
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    int modpow(int a, int n){
        int res = 1;
        while (n){
            if (n & 1) res = res * a % MOD;
            a = (a * a) % MOD;
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

    int n, m, k; cin >> n >> m >> k;

    vector<pii> q(k);
    for (int i = 0; i < k; i++) cin >> q[i].f >> q[i].s;

    sort(all(q), [](pii a, pii b){
        if (a.f == b.f) return a.s < b.s;
        return a.f < b.f;
    });

    q.push_back({n, m});
    k++;
    Comb comb(n + m + 1);
    vector<int> dp(k);

    for (int i = 0; i < k; i++){
        int x = q[i].f, y = q[i].s;
        dp[i] = comb.C(x - 1 + y - 1, x - 1);
        for (int j = 0; j < i; j++){
            if (q[j].f <= x && q[j].s <= y){
                int dx = x - q[j].f;
                int dy = y - q[j].s;
                int way = comb.C(dx + dy, dx);
                dp[i] = ((dp[i] - dp[j] * way % MOD) + MOD) % MOD;
            }
        }
    }
    
    cout << dp[k - 1];
    

    return 0;
}



/*
4 5 5 
2 2 
2 3 
2 4 
4 2 
4 3
*/
