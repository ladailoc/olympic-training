#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    vector<int> v(n);
    f0(i, n) cin >> v[i];

    unordered_map<int, int> mp;
    mp[0] = 1;
    int pref = 0, cnt = 0;
    f0(i, n){
        pref += v[i];
        if (mp.count(pref - x)) cnt += mp[pref - x];
        mp[pref]++;
    }
    cout << cnt;
    return 0;
}

/*
6 7
2 4 1 2 7 7
*/