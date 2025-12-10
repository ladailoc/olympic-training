#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(x + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= x; i++){
        for (auto xx : c){
            if (i >= xx)
                dp[i] = min(dp[i], dp[i - xx] + 1);
        }
    }

    if (dp[x] == 1e18) cout << -1;
    else cout << dp[x];

    return 0;
}