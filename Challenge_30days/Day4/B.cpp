#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    set<int> s1;
    multiset<int> s2;
    s1.insert(0);
    s1.insert(n);
    s2.insert(n);

    while (m--){
        int x; cin >> x;
        auto it1 = s1.upper_bound(x);
        auto it2 = prev(it1);
        s2.erase(s2.find(*it1 - *it2));

        s1.insert(x);
        s2.insert(*it1 - x);
        s2.insert(x - *it2);
        cout << *s2.rbegin() << " ";
    }


    return 0;
}
