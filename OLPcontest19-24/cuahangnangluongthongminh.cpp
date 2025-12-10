#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;

unordered_set<int> se;

void sieve(){
    for (int i = 1; i <= 1e9; i *= 2) se.insert(i);
    for (int i = 1; i <= 1e9; i *= 3) se.insert(i);
    for (int i = 1; i <= 1e9; i *= 5) se.insert(i);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q, x; cin >> n >> q;
    vector<int> v;

    sieve();
    
    for (int i = 0; i < n; i++){
        cin >> x;
        if (se.count(x)) v.push_back(x);
    }

    sort(all(v));

    while (q--){
        int l, r; cin >> l >> r;
        int R = upper_bound(all(v), r) - v.begin() - 1;
        int L = lower_bound(all(v), l) - v.begin();
        cout << R - L + 1 << '\n';
    }

    return 0;
}



/*
5 2 
4 1 7 10 9 
2 4 
1 10 
*/

