#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        se.insert(x);
    }

    cout << se.size();

    return 0;
}