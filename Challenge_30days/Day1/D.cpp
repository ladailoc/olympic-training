#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i + 1;
    sort(all(v));
    
    int i = 0, j = n - 1;
    while (i < j){
        int c = v[i].first + v[j].first;
        if (c == k) {
            cout << v[i].second << ' ' << v[j].second;
            return 0;
        }
        else if (c < k) {
            i++;
        }
        else j--;
    }

    cout << "IMPOSSIBLE";

    return 0;
}