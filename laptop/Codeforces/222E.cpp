#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef vector<i64> vi;
typedef vector<vi> vvi;
const i64 MD = 1e9 + 7;
i64 N, ans;
int M, K;
string st;
inline int gt(char u){ return islower(u)? (u-'a') : (u-'A'+26); }
void operator*=(vvi &l, const vvi &r){
    vvi ret(M, vi(M));
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) for(int k = 0; k < M; ++k)
        (ret[i][j] += (l[i][k] * r[k][j] % MD)) %= MD;
    l.swap(ret);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K; --N;
    vvi ar(M, vi(M, 1)), an(M, vi(M));
    for(int i = 0; i < M; ++i) an[i][i] = 1;
    for(int i = 0; i < K; ++i) cin >> st, ar[gt(st[0])][gt(st[1])] = 0;
    for(i64 i = 1; i <= N; i <<= 1, ar *= ar) // O(M^3 * logN)
        if(N & i) an *= ar;
    for(auto i: an) for(int j: i) (ans += j) %= MD;
    cout << ans;
}