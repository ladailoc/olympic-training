#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

struct node{
    int mn, total, idx;
};

struct Seg{
    int n; vector<node> st;
    Seg(int n): n(n), st(4 * n + 1) {}
    node merge(node a, node b){
        node c;
        if (a.mn <= b.mn) {
            c.mn = a.mn;
            c.idx = a.idx;
        }
        else {
            c.mn = b.mn;
            c.idx = b.idx;
        }
        c.total = a.total + b.total;
        return c;
    }
    void build(const vector<int> &a, int p, int l, int r){
        if (l == r){
            st[p] = {a[l], a[l], l};
            return;
        }
        int m = l + r >> 1;
        build(a, p*2, l, m); 
        build(a, p * 2 + 1, m + 1, r);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update (int p, int l, int r, int idx, int v){
        if (l == r){
            st[p] = {v, v, l};
            return;
        }
        int m = l + r >> 1;
        if (idx <= m) update(p * 2, l, m, idx, v);
        else update(p * 2 + 1, m + 1, r, idx, v);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    node query(int p, int l, int r, int ql, int qr){
        if (ql > r || qr < l) return {LLONG_MAX, 0, -1};
        if (ql <= l && r <= qr) return st[p];
        int m = l + r >> 1;
        return merge(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m + 1, r, ql, qr));
    } 
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    Seg seg(n);
    seg.build(a, 1, 0, n - 1);

    int cur = 0;
    while (q--){
        int c, l, r, p, d; cin >> c;
        if (c == 1){
            cin >> d;
            cur += d; cur %= n;
        }
        else {
            cin >> l >> r;
            l--; r--;
            l = (l - cur + n) % n;
            r = (r - cur + n) % n;
            if (c == 2){
                cin >> p;
                if (l <= r){
                    node k = seg.query(1, 0, n - 1, l, r);
                    seg.update(1, 0, n-1, k.idx, p);
                }
                else {
                    node right = seg.query(1, 0, n-1, 0, r);
                    node left = seg.query(1, 0, n-1, l, n - 1);
                    node ans = seg.merge(left, right);
                    seg.update(1, 0, n-1, ans.idx, p);
                }
            }
            else {
                if (l <= r){
                    node ans = seg.query(1, 0, n - 1, l, r);
                    cout << ans.total << '\n';
                }
                else {
                    node right = seg.query(1, 0, n-1, 0, r);
                    node left = seg.query(1, 0, n-1, l, n - 1);
                    node ans = seg.merge(left, right);
                    cout << ans.total << '\n';
                }
            }
        }
        
    }

    return 0;
}

/*
6 4 
3 4 2 1 6 9 
3 2 4 
1 1 
2 2 4 5 
3 2 4 
*/