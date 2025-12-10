#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
vector<int> spf;
void sieve(){
    spf.resize(MAXN);
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++){
        if (spf[i] == i){
            for (int j = i * i; j < MAXN; j += i){
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<pii> factor(int x){
    vector<pii> v;
    while (x > 1){
        int p = spf[x], cnt = 0;
        while (x % p == 0) x /= p, cnt++;
        v.push_back({p, cnt});
    }
    return v;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    sieve();
    while (t--){
        int n; cin >> n;
        vector<pii> v = factor(n);
        int res = 1;
        for (auto [p, cnt] : v){
            res *= (cnt + 1);
        }
        cout << res  << '\n';
    }

    return 0;
}
