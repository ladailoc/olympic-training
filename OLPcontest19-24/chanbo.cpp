#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, s; cin >> n >> s;
    cout << (n + 1) * n / 2 - s;


    return 0;
}

/*
5 12
*/