// BAI4_DuongDi.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll modpow(ll a, ll e=MOD-2){
    ll r=1;
    while(e){
        if(e&1) r = (r*a)%MOD;
        a=(a*a)%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long m,n;
    int k;
    cin>>m>>n>>k;
    vector<pair<int,int>> pts;
    for (int i=0;i<k;i++){
        int x,y; cin>>x>>y;
        // only consider points that are within grid and reachable
        if (x>=1 && x<=m && y>=1 && y<=n) pts.emplace_back(x,y);
    }
    // include destination
    pts.emplace_back((int)m,(int)n);
    sort(pts.begin(), pts.end(), [](const pair<int,int>& A, const pair<int,int>& B){
        if (A.first != B.first) return A.first < B.first;
        return A.second < B.second;
    });
    // compute max sum dx+dy needed for factorial
    int maxCoordSum = 0;
    for (auto &p: pts) {
        maxCoordSum = max(maxCoordSum, p.first + p.second);
    }
    int MAX = maxCoordSum + 5; // safe
    vector<long long> fact(MAX+1,1), invfact(MAX+1,1);
    for (int i=1;i<=MAX;i++) fact[i] = fact[i-1]*i % MOD;
    invfact[MAX] = modpow(fact[MAX]);
    for (int i=MAX;i>0;i--) invfact[i-1] = invfact[i]*i % MOD;
    auto comb = [&](int a, int b)->long long{ // C(a,b)
        if (b<0 || b> a) return 0;
        return fact[a]* (invfact[b]*invfact[a-b]%MOD) % MOD;
    };
    auto ways = [&](int x1,int y1,int x2,int y2)->long long{
        if (x2 < x1 || y2 < y1) return 0;
        int dx = x2 - x1;
        int dy = y2 - y1;
        return comb(dx+dy, dx);
    };
    int P = pts.size();
    vector<long long> dp(P,0);
    for (int i=0;i<P;i++){
        int xi = pts[i].first, yi = pts[i].second;
        dp[i] = ways(1,1, xi, yi);
        for (int j=0;j<i;j++){
            int xj = pts[j].first, yj = pts[j].second;
            if (xj <= xi && yj <= yi){
                long long w = ways(xj, yj, xi, yi);
                dp[i] = (dp[i] - dp[j] * w) % MOD;
                if (dp[i] < 0) dp[i] += MOD;
            }
        }
    }
    // last point is (m,n)
    cout << dp[P-1] % MOD << "\n";
    return 0;
}
