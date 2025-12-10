#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

const int MOD = 1e9 + 7;

int uoc(int n){
    int ans = 0;
    double k = sqrt(n);
    for (int i = 1; i < k; i++){
        if (n % i == 0) ans += i + n / i;
    }
    if (k*k == n) ans += k;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + uoc(i)) % MOD;
    cout << ans;
    return 0;
}


/*

*/
