#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int l, r, a, k; cin >> l >> r >> a >> k;

    int g = __gcd(a, k);
    int t = k / g;
    cout << (r / t) - ((l - 1) / t);

    return 0;
}

/*
1 10 2 10
*/