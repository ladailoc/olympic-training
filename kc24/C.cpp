// BAI3_BaSoNguyenTo.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

vector<int> sieve_primes(int limit){
    vector<char> is(limit+1, true);
    is[0]=is[1]=false;
    for (int i=2;i*i<=limit;i++) if (is[i])
        for (int j=i*i;j<=limit;j+=i) is[j]=false;
    vector<int> primes;
    for (int i=2;i<=limit;i++) if (is[i]) primes.push_back(i);
    return primes;
}

ll safe_pow(ll base, ll exp, ll R) {
    i128 res = 1;
    i128 b = base;
    while (exp){
        if (exp&1){
            res = res * b;
            if (res > (i128)R) return R+1;
        }
        exp >>= 1;
        if (exp){
            b = b * b;
            if (b > (i128)R) b = (i128)R+1;
        }
    }
    ll out = (ll)res;
    return out;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long L,R;
    int K;
    if(!(cin>>L>>R>>K)) return 0;
    // generate primes up to something reasonable.
    // heuristic: primes up to 2e6 should be enough for typical constraints; increase if needed.
    int LIMIT = 2000000; // adjust if necessary
    vector<int> primes = sieve_primes(LIMIT);
    // ensure we have enough primes until prime^1 <= R => primes up to R; but if R large, LIMIT might be too small.
    // For contest constraints in pdf, R likely <= 1e12 or similar; LIMIT=2e6 usually enough.
    // enumerate factorizations of K into f1*f2*f3 with fi >= 2
    vector<int> divs;
    for (int d=1; d*d<=K; ++d){
        if (K % d == 0){
            divs.push_back(d);
            if (d*d != K) divs.push_back(K/d);
        }
    }
    sort(divs.begin(), divs.end());
    vector<array<int,3>> triples;
    for (int i=0;i<divs.size();++i){
        int d1 = divs[i];
        if (d1 < 2) continue;
        for (int j=0;j<divs.size();++j){
            int d2 = divs[j];
            if (d2 < 2) continue;
            if ((long long)d1 * d2 > K) continue;
            if (K % (d1*d2) != 0) continue;
            int d3 = K / (d1*d2);
            if (d3 < 2) continue;
            triples.push_back({d1, d2, d3});
        }
    }
    // consider permutations of exponents (since mapping to p1,p2,p3 is ordered)
    long long best = -1;
    int P = primes.size();
    for (int i=0;i+2<P;i++){
        ll p1 = primes[i], p2 = primes[i+1], p3 = primes[i+2];
        // quick prune: if p1*p2*p3 > R (even with exponent 1), maybe larger exponents impossible
        i128 minimal = (i128)p1 * p2 * p3;
        if (minimal > (i128)R) {
            // since primes increasing, further i will be larger -> break
            break;
        }
        for (auto tr : triples){
            int f1 = tr[0], f2 = tr[1], f3 = tr[2];
            // we must map f => ei+1, so exponent = f-1
            vector<int> perm = {f1,f2,f3};
            sort(perm.begin(), perm.end());
            do {
                ll e1 = perm[0]-1, e2 = perm[1]-1, e3 = perm[2]-1;
                // compute p1^e1 * p2^e2 * p3^e3 safely
                ll a = safe_pow(p1, e1, R);
                if (a > R) continue;
                ll b = safe_pow(p2, e2, R / max(1LL,a));
                if (b > R) continue;
                ll ab;
                if ((__int128)a * b > (__int128)R) continue;
                ab = a * b;
                ll c = safe_pow(p3, e3, R / max(1LL,ab));
                if (c > R) continue;
                __int128 val = (__int128)ab * c;
                if (val < (__int128)L || val > (__int128)R) continue;
                long long vll = (long long)val;
                if (vll > best) best = vll;
            } while(next_permutation(perm.begin(), perm.end()));
        }
    }
    // Problem guarantees existence
    cout << best << "\n";
    return 0;
}
