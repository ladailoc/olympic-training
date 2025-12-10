#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
const int MOD = 1e9 + 7;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    int mn = LLONG_MAX;
    for (int i = 0; i < n; i++){
        double u, v, l; cin >> u >> v >> l;
        double dist = sqrt((u - a) * (u - a) + (v - b) * (v - b)) - l;
        dist = ceil(dist) - 1;
        mn = min(mn, (int)dist);
    }
    cout << mn;
    return 0;
}

/*
1 0 0
0 9 3
*/