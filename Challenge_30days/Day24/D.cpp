#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    const int MAX = 1e6;
    vector<int> cnt(MAX + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int d = MAX; d >= 1; d--) {
        int total = 0;
        for (int multiple = d; multiple <= MAX; multiple += d) {
            total += cnt[multiple];
            if (total >= 2) {
                cout << d;
                return 0;
            }
        }
    }

    return 0;
}


/*

*/
