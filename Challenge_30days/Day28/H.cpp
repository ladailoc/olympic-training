#include <bits/stdc++.h>    
using namespace std;

#define int long long
#define pii pair<int, int>

struct Point{
    int x, y;
};

Point operator-(Point A, Point B) {
    Point C;
    C.x = A.x - B.x;
    C.y = A.y - B.y;
    return C;
}



signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    Point A, B, C; cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    
    Point BC = B - C;
    Point n = {-BC.y, BC.x};
    int c = -(n.x * B.x + n.y * B.y);

    cout << fixed << setprecision(9) << abs(n.x * A.x + n.y * A.y + c) / sqrt(n.x * n.x + n.y * n.y);

    return 0;

}