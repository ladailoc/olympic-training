#include <bits/stdc++.h>
using namespace std;


#define int long long 
#define pii pair<int, int>
struct Point{
    int x, y;
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    Point A, B; cin >> A.x >> A.y >> B.x >> B.y;
    
    pii ab = {B.x - A.x, B.y - A.y};
    pii n = {-ab.second, ab.first};

    cout << n.first << ' ' << n.second << ' ' << -n.first * A.x - n.second * A.y;


    return 0;
}