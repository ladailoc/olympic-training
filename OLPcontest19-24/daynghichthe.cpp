#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

int n;

struct BIT{
    int n; vector<int> f;
    BIT(int n = 0): n(n), f(n + 1, 0){}

    void add(int i, int v){
        for (; i <= n; i += i & -i) f[i] += v;
    }
    int sum(int i){
        int res = 0;
        for (; i > 0; i-=i&-i) res += f[i];
        return res;
    }
    int range_sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    BIT bit(mx + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bit.range_sum(a[i] + 1, mx);
        bit.add(a[i], 1);
    }

    cout << ans;

    return 0;
}

/*
3
3
1
2
*/