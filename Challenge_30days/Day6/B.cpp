#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    list<int> lst;
    for(int i = 1; i <= n; i++) lst.push_back(i);
    auto it = lst.begin();
    vector<int> ans;
    while (lst.size() > 0) {
        if (it == lst.end()) it = lst.begin();
        it++;
        if (it == lst.end()) it = lst.begin();
        ans.push_back(*it);
        it = lst.erase(it);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

