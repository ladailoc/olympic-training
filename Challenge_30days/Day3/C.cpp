#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
vector<int> v;
int n;
bool ok(int m){
    int sum = 1;
    for(int i = 0; i < n; i++){
        if (v[i] > sum) break;
        sum += v[i];
        if (sum > m) return true;
    }
    return sum > m;
}

int bs(int l, int r){
    while (l < r){
        int m = l + r >> 1;
        if (ok(m)) l = m+1;
        else r = m;
    }

    return l;

}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    cout << bs(1, 1e18);

    return 0;
}
