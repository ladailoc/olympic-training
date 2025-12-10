#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int k; string s; cin >> k >> s;
    s = ' ' + s; 
    int n = s.size();
    vector<int> preV(n, 0), preC(n, 0), preA(n, 0);
    for(int i = 1; i < n; i++){
        preV[i] = preV[i - 1] + (s[i] == 'V');
        preC[i] = preC[i - 1] + (s[i] == 'C');
        preA[i] = preA[i - 1] + (s[i] == 'A');
    } 

    // for (int i = 0; i < preV.size(); i++) cout << preV[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < preV.size(); i++) cout << preC[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < preV.size(); i++) cout << preA[i] << ' ';
    // cout << endl;
    int l = 1, r = 3 * k, mn = LLONG_MAX, v, c, a;
    while (r < n){
        a = preA[r] - preA[l - 1];
        c = preC[r] - preC[l - 1];
        v = preV[r] - preV[l - 1];
        while (a >= k && v >= k && c >= k){
            mn = min({mn, r - l + 1 - 3 * k});
            // cout << " l r: " << l << " " << r << endl;
            // cout << "a c v : " << a << ' ' << c << ' ' << v << endl;
            // cout << "min : " << r - l + 1 - 3 * k << endl;
            l++;
            a = preA[r] - preA[l - 1];
            c = preC[r] - preC[l - 1];
            v = preV[r] - preV[l - 1];
        }

        r++;
    }

    cout << mn;

    return 0;
}

/*
2 
AVVAVCAVVCCCVA


A V V A V C A V V C C C V A

*/