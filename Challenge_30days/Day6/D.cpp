#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int ans = 1;
    for (auto [val, count] : freq){
        ans = (ans * (count + 1)) % MOD;
    }

    cout << ans - 1;

    return 0;

}