#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second
int n, f0, d; 
bool check(pii a, pii b){
    pii c = {b.f - a.f, b.s - a.s};
    return c.f * c.f + c.s * c.s < d * d;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> f0 >> d;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].f >> v[i].s;

    vector<int> used(n + 1, 0);
    vector<int> f11;
    f0--;
    used[f0] = 1;
    for (int i = 0; i < n; i++){
        if (!used[i] && check(v[f0], v[i])) {
            f11.push_back(i);
            used[i] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < f11.size(); i++){
        for (int j = 0; j < n; j++) {
            if (!used[j] && check(v[f11[i]], v[j])) {
                cnt++;
                used[j] = 1;
            }
        }
    }

    cout << f11.size() << ' ' << cnt;
    return 0;
}

/*
5 4 2 
2 2 
0 0 
0 2 
1 1 
2 3 
*/