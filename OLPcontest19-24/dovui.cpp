#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define f first
#define s second

int n, m; string s; 
string res;

int check(string s){
    for (int i = 0; i < m; i++){
        if (s[i] != s[i + m]) return 0;
    }
    return 1;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    m = n / 2;
    if (n % 2 == 0){
        cout << "No Solution";
        return 0;
    } 
    string tmp;
    int ok = 0;
    for (int i = 0; i < s.size(); i++){
        tmp = s.substr(0, i) + s.substr(i + 1);
        if (check(tmp)){
            ok++;
            if (ok == 1) res = tmp.substr(0, m);
        }
    }
    if (ok == 0) cout << "No Solution";
    else if (ok >= 2)
        cout << "Multiple Solutions";
    else cout << res;


    return 0;
}

/*
9
GKGKGKGKG

10
HELLOWORLD


*/
