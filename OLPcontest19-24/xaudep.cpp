#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

int n, q;
string s;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q >> s;
    s = ' ' + s;
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int bit = 1 << (s[i] - 'a');
        pre[i] = pre[i - 1] ^ bit;
    }

    while(q--){
        int l, r; cin >> l >> r;
        l++, r++;
        int mask = pre[r] ^ pre[l - 1];
        cout << __builtin_popcount(mask) / 2 << '\n';
    }

    return 0;
}

/*
8 3 
abcaacba 
1 3 
2 7 
1 6

*/