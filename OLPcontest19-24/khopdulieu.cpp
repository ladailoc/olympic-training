#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

int n, q;

struct Seg{
    int n; vector<int> st;
    Seg(int n = 0): n(n), st(4 * n + 1, 0){}
    void build(const vector<int> &a, int p, int l, int r){
        if (l == r){
            st[p] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(a, 2 * p, l, m);
        build(a, 2 * p + 1, m + 1, r);
        st[p] = __gcd(st[2 * p], st[2 * p + 1]);
    }
    int query(int p, int l, int r, int ql, int qr){
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[p];
        int m = l + r >> 1;
        return __gcd(query(p * 2, l, m, ql, qr), query(p * 2+ 1, m + 1, r, ql, qr));
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    vector<int> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        d[i] = abs(a[i] - b[i]);
    }

    Seg seg(n);
    seg.build(d, 1, 0, n - 1);

    while (q--){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << seg.query(1, 0, n - 1, l, r) << '\n';
    }

    return 0;
}

/*

*/