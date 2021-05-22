#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef vector<i64> vi;
typedef vector<vi> vvi;
const i64 MD = 1e9 + 7;
i64 N, sm;
int M;
void operator*=(vvi &u, const vvi &v){
    vvi tem(u.size(), vi(v[0].size()));
    for(int i = 0; i < u.size(); ++i) for(int j = 0; j < v[0].size(); ++j) for(int k = 0; k < v.size(); ++k)
        (tem[i][j] += (u[i][k] * v[k][j] % MD)) %= MD;
    u.swap(tem);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vvi ar(M, vi(M)), xp(M, vi(M));
    ar[0][0] = ar[0][M - 1] = xp[0][0] = 1;
    for(int i = 1; i < M; ++i) ar[i][i - 1] = 1, xp[i][i] = 1;
    for(i64 i = 1; i <= N; i <<= 1, ar *= ar)
        if(i & N) xp *= ar;
    cout << xp[0][0];
}