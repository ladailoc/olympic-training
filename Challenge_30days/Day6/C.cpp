#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct BIT {
    int n; vector<int> f;
    BIT(int n = 0): n(n), f(n + 1, 0) {}
    void add(int i, int v) {
        for (; i <= n; i+=i&-i) f[i] += v;
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i-=i&-i) res += f[i]; 
        return res;
    }
    // tìm vị trí nhỏ nhất p sao cho sum(p) >= k
    int kth(int k){
        int p = 0;
        int pw = 1 << (31 - __builtin_clz(n));
        for(; pw; pw >>= 1){
            int np = p + pw;
            if (np <= n && f[np] < k){
                k -= f[np];
                p = np;
            }
        }
        return p + 1;
    }

};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    BIT bit(n);
    for(int i = 1; i <= n; i++) bit.add(i, 1);

    int idx = 0;
    for (int rem = n; rem >= 1; rem--){
        idx = (idx + k) % rem;
        int pos = bit.kth(idx + 1);
        cout << pos << " ";
        bit.add(pos, -1);
    }
    

    return 0;
}