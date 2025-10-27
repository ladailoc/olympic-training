#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int i = 0, j = n-1, cnt = 0;
    while (i < j){
        if (a[i] + a[j] <= x) {
            i++, j--;
        }
        else j--;
        cnt++;
    }
    if (i == j) cnt++;
    cout << cnt;
    return 0;
}