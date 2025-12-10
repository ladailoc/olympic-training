#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
struct node {
    int val, total, idx;
};  
struct Seg{
    int n; vector<node> tree;
    Seg(int sz){
        n = sz;
        tree.resize(4 * n + 10);
    }
    node mergeNode (node a, node b) {
        node res;
        res.total = a.total + b.total;
        if (a.val <= b.val) {
            res.val = a.val;
            res.idx = a.idx;
        }
        else {
            res.val = b.val;
            res.idx = b.idx;
        }

        return res;
    }
    void build(const vector<int>& v, int p, int l, int r){
        if (l == r){
            tree[p] = {v[l], v[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(v, p * 2, l, mid);
        build(v, p * 2 + 1, mid + 1, r);
        tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val){
        if (l == r){
            tree[p] = {val, val, l};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(p * 2, l, mid, idx, val);
        else update(p * 2 + 1, mid + 1, r, idx, val);
        tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
    }
    node query(int p, int l, int r, int ql, int qr){
        if (ql > r || qr < l) return {LLONG_MAX, 0, -1};
        if (ql <= l && r <= qr) return tree[p];
        int mid = (l + r) / 2;
        return mergeNode(query(p * 2, l, mid, ql, qr), query(p * 2 + 1, mid + 1, r, ql, qr));
    }
};

int cur = 0;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    Seg seg(n);
    seg.build(v, 1, 0, n - 1);

    for (int i = 0; i < q; i++){
        int c; cin >> c;
        if (c == 1) {
            int d; cin >> d;
            cur += d;
            cur %= n;
        }
        else if (c == 2) {
            int l, r, p; cin >> l >> r >> p;
            l--, r--;
            l = (l - cur + n) % n;
            r = (r - cur + n) % n;
            if (l > r) {
                auto left = seg.query(1, 0, n - 1, l, n - 1);
                auto right = seg.query(1, 0, n - 1, 0, r);
                auto ans = seg.mergeNode(left, right);
                seg.update(1, 0, n - 1, ans.idx, p);
            }
            else {
                auto ans = seg.query(1, 0, n - 1, l, r);
                seg.update(1, 0, n - 1, ans.idx, p);
            }
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;
            l = (l - cur + n) % n;
            r = (r - cur + n) % n;
            if (l > r) {
                auto left = seg.query(1, 0, n - 1, l, n - 1);
                auto right = seg.query(1, 0, n - 1, 0, r);
                auto ans = seg.mergeNode(left, right);
                cout << ans.total << "\n";
            }
            else {
                auto ans = seg.query(1, 0, n - 1, l, r);
                cout << ans.total << "\n";
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