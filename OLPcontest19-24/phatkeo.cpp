#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

bool check(int idx, int k){
    if (idx % k == 0) return true;
    while (idx){
        if (idx % 10 == k) return true;
        idx /= 10;
    } 
    return 0;
}

int getVal(int idx, int n, int k){
    if (check(idx, k)) return n * 2;
    return n;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    while (q--){
        int c; cin >> c;
        if (c == 1){
            int id, val; cin >> id >> val;
            v[id] = val;
        }
        else {
            int l, r, k; cin >> l >> r >> k;
            int ans = 0;
            for (int i = l; i <= r; i++){
                ans += getVal(i, v[i], k);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}

/*
16 4 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
2 1 5 2 
2 14 16 4 
1 14 24 
2 14 16 4
*/