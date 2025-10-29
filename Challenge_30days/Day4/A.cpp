#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && v[st.top()] >= v[i]) st.pop();
        cout << (st.empty() ? 0: st.top()) << ' ';
        st.push(i);
    }


    return 0;
}
