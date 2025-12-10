#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

int n, m; 
vector<int> a;

bool ok(int t){
    vector<int> mxLeft(n), mxRight(n), b(n);
    for(int i = 0; i < n; i++){
        b[i] = max(a[i], t);
    }

    for (int i = 0; i < n; i++) {
        mxLeft[i] = b[i];
        if (i > 0) mxLeft[i] = max(mxLeft[i], mxLeft[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        mxRight[i] = b[i];
        if (i < n - 1) mxRight[i] = max(mxRight[i], mxRight[i + 1]);
    }

    int cur = 0;
    for (int i = 0; i < n; i++){
        cur += min(mxLeft[i], mxRight[i]) - b[i];
        if (cur >= m) return true; 
    }
    return false;
}

int bs(int lo, int hi){
    int ans = 0;
    while (lo <= hi){
        int m = lo + hi >> 1;
        if (ok(m)) lo = m + 1, ans = m;
        else hi = m - 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    a.resize(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    
    if (!ok(0)) {
        cout << -1;
        return 0;
    }

    int lo = 0;
    int hi = *max_element(all(a));
    cout << bs(lo, hi);

    return 0;
}

/*
7 4 
4 1 3 2 5 1 6 
*/