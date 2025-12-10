#include <bits/stdc++.h>
using namespace std;

// #define int long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int> 
#define f first
#define s second

const int MOD = 1e9 + 7;

const int MAXN = 1e6 + 7;

vector<int> spf (MAXN);
void sieve(){
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++){
        if (spf[i] == i) 
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) 
                    spf[j] = i; 
    }
}

vector<pii> factorize(int x){
    vector<pii> v;
    while (x > 1) {
        int p = spf[x], cnt = 0;
        while (x % p == 0) x /= p, cnt++;
        v.push_back({p, cnt});
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();

    int t; cin >> t;
    while (t--){
        int n, x; cin >> n;
        vector<int> cnt(MAXN, 0);
        for (int i = 0; i < n; i++){
            cin >> x;
            vector<pii> f = factorize(x);
            for (auto [v, l] : f){
                if (v != 2 && v != 5)
                    cnt[v] += l;
            }
        }
        int check = 0;

        for (int i = 0; i < n; i++){
            cin >> x;
            vector<pii> f = factorize(x);
            for (auto [v, l] : f){
                if (v != 2 && v != 5){
                    cnt[v] -= l;
                    if (cnt[v] < 0) {
                        check = 1;
                    }
                }
            }
        }
        
        if (check) cout << "repeating\n";
        else cout << "finite\n";
    }
    
    

    return 0;
}



/*
4 
2 1 7 5 6 
1 3 20 
1 4 1 
1 116 495 
*/

