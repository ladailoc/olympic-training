#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
int a, b, m;
struct Matrix {
    int a[2][2];
};

Matrix mul(Matrix A, Matrix B){
    Matrix C;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            C.a[i][j] = 0;
            for (int k = 0; k < 2; k++){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % m) % m; 
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> m;



    return 0;
}
