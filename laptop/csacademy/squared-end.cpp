#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 1e4 + 5, HI = 1e6 + 5;
const long INF = 1e18;
struct one{
    long m, c;
    long operator()(long x){ return (max(m, c) >= INF? INF : (m * x + c)); }
    one(long _m, long _c) : m(_m), c(_c) {}
};
int N, K; long ar[X];
vector<long> dp(X, INF);
vector<one> tr;
void add(one nw){
    int l = 0, r = HI - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(nw(m) < tr[m](m)) swap(nw, tr[m]);
        if(nw(l) < tr[m](l)) r = m - 1;
        else if(nw(r) < tr[m](r)) l = m + 1;
        else break;
    }
}
long gt(int x, long ret = INF){
    int l = 0, r = HI - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        ret = min(ret, tr[m](x));
        if(x < m) r = m - 1;
        else if (x > m) l = m + 1;
        else break;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) cin >> ar[i];
    dp[0] = 0;
    for(int i = 0; i < K; ++i){
        vector<long> cdp(X, INF);
        tr.assign(HI, one(0, INF));
        for(int j = 1; j <= N; ++j){
            add(one(-ar[j] * 2ll, ar[j] * ar[j] + dp[j - 1]));
            cdp[j] = min(INF, gt(ar[j]) + ar[j] * ar[j]);
        }
        dp = cdp;
    }
    cout << dp[N];
}