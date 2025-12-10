#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

const int MOD = 1e9+7;

struct Seg{
    int n; vector<int> st;
    Seg(int n) : n(n), st(4 * n + 1) {}
    void build(const vector<int> &a, int p, int l, int r){
        if (l == r){
            st[p] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(a, p * 2, l, m);
        build(a, p * 2 + 1, m + 1, r);
        st[p] = min(st[p * 2], st[p * 2 + 1]);
    }
    void update(int p, int l, int r, int idx, int v){
        if (l == r){
            st[p] = v;
            return;
        }
        int m = l + r >> 1;
        if (idx <= m) update(p * 2, l, m, idx, v);
        else update(p * 2+1, m + 1, r, idx, v);
        st[p] = min(st[p * 2], st[p * 2 + 1]);
    }
    int query(int p, int l, int r, int ql, int qr){
        if (ql > r || qr < l) return LLONG_MAX;
        if (ql <= l && r <= qr) return st[p];
        int m = l + r >> 1;
        return min(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m + 1, r, ql, qr));
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < m; i++) cin >> b[i];
    
    sort(all(b));
    vector<int> mn(n);
    for (int i = 0; i < n; i++){
        int id = lower_bound(all(b), a[i]) - b.begin();
        if (id == m) id--;
        mn[i] = abs(a[i] - b[id]);
        if (id > 0) mn[i] = min(mn[i], abs(a[i] - b[id - 1]));
    }

    Seg seg(n);
    seg.build(mn, 1, 0, n - 1);

    while (k--){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << seg.query(1, 0, n - 1, l, r) << '\n';
    }
    return 0;
}

/*
3 4 3 
1 5 7 
4 -1 3 9 
1 3 
1 1 
2 2 
*/