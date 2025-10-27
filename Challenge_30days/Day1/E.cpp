#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pii> a;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }

    sort(all(a));
    int mx = 0, cur = 0;
    for (int i = 0 ; i < a.size(); i++){
        cur += a[i].second;
        mx = max (mx, cur);
    }

    cout << mx;

    return 0;
}