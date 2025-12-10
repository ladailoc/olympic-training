#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 
#define f first
#define s second

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    int k = n - 1;
    for (int i = 0; i < n; i++){
        if ((i & k) == i) ans ^= v[i];
    }

    cout << ans;
    

    return 0;
}



/*
3 
1 2 3 
*/
