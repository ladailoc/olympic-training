#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    unordered_map<int, int> mp;
    int cur = 0, ans = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        cur += x;
        cur = (cur % n + n) % n;
        if (mp.count(cur))
            ans += mp[cur];
        mp[cur]++;
    }

    cout << ans;

    return 0;
}
