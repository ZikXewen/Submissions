#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef vector<i64> vi;
typedef vector<vi> vvi;
const i64 MD = 98765431;
int T;
i64 N;
void operator*=(vvi &u, const vvi &v){
    vvi ret(3, vi(3));
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) for(int k = 0; k < 3; ++k)
        (ret[i][j] += (u[i][k] * v[k][j] % MD)) %= MD;
    u.swap(ret);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    for(int i = 0; i < T; ++i){
        i64 ans = 0;
        vvi ex(3, vi(3, 1)), an(3, vi(3)); 
        ex[0][0] = ex[1][1] = 0;
        an[0][0] = an[1][1] = an[2][2] = 1;
        cin >> N; --N;
        for(i64 j = 1; j <= N; j <<= 1, ex *= ex)
            if(j & N) an *= ex;
        for(auto j: an) for(i64 k: j) (ans += k) %= MD;
        cout << ans << '\n';
    }
}