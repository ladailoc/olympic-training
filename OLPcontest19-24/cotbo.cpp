#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double n, a, b; cin >> n >> a >> b;
    int mn = 1e18;
    for (int i = 0; i < n; i++){
        double x, y, r; cin >> x >> y >> r;
        double d = sqrt((x - a) * (x - a) + (y - b) * (y - b)) - r;
        d = ceil(d) - 1;
        mn = min(mn, (int)d);
    }
    
    cout << mn; 


    return 0;
}

/*
1 0 0 
0 9 3 
*/