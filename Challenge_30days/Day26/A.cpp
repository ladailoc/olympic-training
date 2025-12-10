#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= 6; x++){
            if (i - x >= 0){
                dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
        }
    }   

    cout << dp[n];


    return 0;
}