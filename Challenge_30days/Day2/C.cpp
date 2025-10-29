#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f0(i, n) for(int i = 0; i < n; i++)
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    f0(i, n) cin >> v[i];
    
    multiset<int> se;
    int j = 0, mx = 0;
    f0(i, n){
        while (se.count(v[i])) {
            se.erase(v[j++]);
        }
        se.insert(v[i]);
        mx = max(mx, (int)se.size());
    }

    cout << mx;
    return 0;
}