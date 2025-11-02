#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

struct DSU{
    int n; vector<int> p, sz;
    DSU(int n = 0) {init(n);}
    void init(int n){
        p.resize(n + 1); sz.assign(n+1, 1);
        iota(all(p), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        dsu.unite(a, b);
    }

    vector<pii> a;
    for (int i = 2; i <= n; i++){
        if (dsu.unite(1, i))
            a.push_back({1, i});
    }

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); i++) cout << a[i].first << " " << a[i].second << '\n'; 

    
    return 0;
}