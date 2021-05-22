#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef vector<i64> vi;
typedef vector<vi> vvi;
const int M = 4;
const i64 MD = 1e9 + 7;
i64 N;
void operator*=(vvi &u, const vvi &v){
    vvi tem(M, vi(M));
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) for(int k = 0; k < M; ++k)
        (tem[i][j] += (u[i][k] * v[k][j] % MD)) %= MD;
    u.swap(tem);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vvi ar(M, vi(M, 1)), xp(M, vi(M));
    for(int i = 0; i < M; ++i) ar[i][i] = 0, xp[i][i] = 1;
    for(i64 i = 1; i <= N; i <<=1, ar *= ar)
        if(i & N) xp *= ar;
    cout << xp[0][0];
}