#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f0(i, n) for(int i = 0; i < n; i++)
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    
    vector<int> v(n);
    f0(i, n) cin >> v[i];
    
    int mx = INT_MIN, cur = 0;
    f0(i, n) {
        cur = max(cur + v[i], v[i]);
        mx = max(mx, cur);
    }

    cout << mx;
    return 0;
}