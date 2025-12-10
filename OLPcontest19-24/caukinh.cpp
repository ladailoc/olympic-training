#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

const int MOD = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        vector<vector<int>> dp(2, vector<int>(a.size(), 0));
        
        if (a[0] == 'X') dp[0][0] = 1;
        if (b[0] == 'X') dp[1][0] = 1;
        int n = a.size();
        for(int i = 1; i < n; i++){
            if (a[i] == 'X') dp[0][i] = (dp[0][i - 1] + dp[1][i-1]) % MOD;   
            if (b[i] == 'X') dp[1][i] = (dp[0][i - 1] + dp[1][i-1]) % MOD;
        }

        cout << (dp[0][n - 1] + dp[1][n-1]) % MOD << '\n'; 
    }
    
    return 0;
}

/*
3 
OOXXXOOOXO
XXXOXXXOOX
XXOXXOXO
OOXOXXXX
OOOXXXOXOXOX
XXXOOOXXXOXO
*/