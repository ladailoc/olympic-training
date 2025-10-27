#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m){
        if (abs(a[i] - b[j]) <= k) {
            i++, j++, cnt++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else i++;
    }

    cout << cnt;
    return 0;
}