#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

const int MOD = 1e9 + 7;

int mu(int a, int b, int MOD){
    int res = 1;
    while (b){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;

}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;

        cout << mu(a, b, MOD)  << '\n';


    }

    return 0;
}
