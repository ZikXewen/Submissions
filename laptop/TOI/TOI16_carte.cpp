//WIP
#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 405;
int R, K, N, in[X], mx;
ii ar[X][X];
ii operator+(const ii &l, const ii &r){
    return (l.y + r.y > K)? ii(l.x + r.x + 1, 1) : ii(l.x + r.x, l.y + r.y);
}
ii dp(int u, int v){
    if(ar[u][v] != ii(-1, -1)) return ar[u][v];
    if(u > v) return ar[u][v] = ii(0, 0);
    ii ret = ii(min(v - u + 1, 1 + dp(u + 1, v).x), 1);
    for(int i = u + 1; i <= v; ++i) if(in[i] == in[u]) ret = min(ret, ii(dp(u + 1, i - 1).x, 1) + dp(i, v));
    return ar[u][v] = ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> K;
    while(R--){
        memset(ar, -1, sizeof ar);
        cin >> N;
        for(int i = 0; i < N; ++i) cin >> in[i];
        mx = max(mx, dp(0, N - 1).x);
    }
    cout << mx;
}