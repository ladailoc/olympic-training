#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    int cur = 0;
    for (int i = 2; i <= r; i *= 2){
        // cout << cur << " ";
        cur += (r / i) - ((l - 1) / i);
    }

    cout << cur;

    return 0;
}

/*
7 4 
4 1 3 2 5 1 6 
*/