#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> v;
int n, t;
bool ok(int m){
    int cur = 0;
    for (int i = 0; i < n; i++){
        cur += (m / v[i]);
        if (cur >= t) return true;
    }
    return cur >= t;
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

    cout << bs(0, 1e18);

    return 0;
}
