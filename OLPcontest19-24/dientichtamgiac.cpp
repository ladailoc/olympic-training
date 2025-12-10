#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int u, v; cin >> u >> v;
    int s = u * u + v * v;
    int nguyen = s / 4;
    int du = s % 4;
    cout << nguyen << '.';
    if (du == 0) cout << "00";
    else if (du == 1) cout << "25";
    else if (du == 2) cout << "50";
    else cout << "75";
    return 0;
}

/*
6 9 10
*/