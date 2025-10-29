#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> v;
int n, t;
bool ok(int m){
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++){
        if (sum + v[i] <= m){
            sum += v[i];
        }
        else {
            cnt++;
            sum = v[i];
        }
    }
    return cnt + 1 <= t;
}

int bs(int l, int r){
    while (l < r){
        int m = l + r >> 1;
        if (ok(m)) r = m;
        else l = m+1;
    }

    return l;

}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int mn = *max_element(v.begin(), v.end());
    cout << bs(mn, 1e18);

    return 0;
}
