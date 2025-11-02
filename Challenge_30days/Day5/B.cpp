#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, sum = 0; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i], sum += v[i];

    int mn = LLONG_MAX;
    for (int i = 0; i < 1 << n; i++){
        int cur = 0;
        for (int j = 0; j < n; j++){
            if ((i >> j) & 1) {
                cur += v[j];
            }
        }
        mn = min({mn, abs(sum - 2*cur)});
    }

    cout << mn;

    return 0;
}
