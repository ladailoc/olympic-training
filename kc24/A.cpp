#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE = 9113823;

struct Hash {
    vector<int> h1, h2, p1, p2;
    int n;
    Hash(const string &s) {
        n = (int)s.size();
        h1.assign(n+1,0); h2.assign(n+1,0);
        p1.assign(n+1,1); p2.assign(n+1,1);
        for (int i = 0; i < n; i++){
            p1[i+1] = (int)((1LL * p1[i] * BASE) % MOD1);
            p2[i+1] = (int)((1LL * p2[i] * BASE) % MOD2);
            h1[i+1] = (int)(( (1LL*h1[i] * BASE) + (unsigned char)s[i]) % MOD1);
            h2[i+1] = (int)(( (1LL*h2[i] * BASE) + (unsigned char)s[i]) % MOD2);
        }
    }
    pair<int,int> rangeHash(int l, int r){
        if (l>r) return {0,0};
        int x1 = (int)(h1[r+1] - (1LL * h1[l] * p1[r-l+1]) % MOD1);
        if (x1 < 0) x1 += MOD1;
        int x2 = (int)(h2[r+1] - (1LL * h2[l] * p2[r-l+1]) % MOD2);
        if (x2 < 0) x2 += MOD2;
        return {x1,x2};
    }

    static pair<int,int> concat(pair<int,int> a, int la, pair<int,int> b, int lb, const vector<int>& p1, const vector<int>& p2){
        int na = (int)(( (1LL * a.first * p1[lb]) % MOD1 + b.first ) % MOD1);
        int nb = (int)(( (1LL * a.second * p2[lb]) % MOD2 + b.second ) % MOD2);
        return {na, nb};
    }
};

pair<int,int> getHashU(int s, int len, int skip, const string &t, Hash &H) {
    if (len == 0) return {0,0};
    int n = (int)t.size();
    int first_u = s;
    int last_u = s + len - 1;
    // three cases: entirely before skip, entirely after skip, or crosses skip
    if (last_u < skip) {
        // maps to [first_u, last_u] in t
        return H.rangeHash(first_u, last_u);
    } else if (first_u > skip) {
        // maps to [first_u+1, last_u+1] in t
        return H.rangeHash(first_u + 1, last_u + 1);
    } else {
        // crosses skip: map to [first_u, skip-1] and [skip+1, last_u+1]
        pair<int,int> a = H.rangeHash(first_u, skip - 1);
        pair<int,int> b = H.rangeHash(skip + 1, last_u + 1);
        int la = max(0, (skip - 1) - first_u + 1);
        int lb = max(0, last_u + 1 - (skip + 1) + 1); // equals last_u - skip + 1
        return Hash::concat(a, la, b, lb, H.p1, H.p2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    string t; cin >> t;
    if (n % 2 == 0) {
        cout<<"No Solution\n";
        return 0;
    }
    int m = (n-1)/2;
    Hash H(t);

    unordered_set<string> sols;
    sols.reserve(4);

    for (int skip=0; skip<n; ++skip){
        auto hleft = getHashU(0, m, skip, t, H);
        auto hright = getHashU(m, m, skip, t, H);
        if (hleft == hright) {
            // build candidate s (length m)
            string s;
            s.reserve(m);
            for (int j=0;j<m;j++){
                int t_idx = (j < skip) ? j : j+1;
                s.push_back(t[t_idx]);
            }
            sols.insert(s);
            if (sols.size() > 1) break; // enough to know Multiple Solutions
        }
    }

    if (sols.empty()) {
        cout << "No Solution\n";
    } else if (sols.size() > 1) {
        cout << "Multiple Solutions\n";
    } else {
        cout << *sols.begin() << "\n";
    }
    return 0;
}
