#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    vector<string> v;
    sort(s.begin(), s.end());
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << v.size() << '\n';

    for (auto x: v) cout << x << "\n";

    return 0;
}
