#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pi acos(-1)
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int u, v; cin >> u >> v;

    int num = u * u + v * v;
    int s = num / 4;
    int m = num % 4;
    cout << s << '.';
    if (m == 0) cout << "00";
    else if (m == 1) cout << "25";
    else if (m == 2) cout << "50";
    else cout << "75";
    return 0;
}


