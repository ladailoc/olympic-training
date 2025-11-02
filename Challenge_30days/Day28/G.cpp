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
    
    double tu = A.x * B.x + A.y * B.y;
    double mau = sqrt(A.x * A.x + A.y * A.y) * sqrt(B.x * B.x + B.y * B.y);
    cout << fixed << setprecision(9) << acos(tu / mau);

    return 0;
}