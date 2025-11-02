#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = se.upper_bound(x);
        if (it != se.end()) se.erase(it);
        se.insert(x);
    }

    cout << se.size();

    return 0;
}
