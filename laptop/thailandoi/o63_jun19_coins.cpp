#include <bits/stdc++.h>
#define remax(a, b) (a) = max((a), (b))
#define remin(a, b) (a) = min((a), (b))
#define iii tuple<int, int, int>
using namespace std;
const int X = 1e6 + 5, INF = 2e9;
int N, dis[X], mx, dp[X], ndp[X], tr[2][X << 3], an;
vector<int> ar[X];
stack<iii> stk;
int cos(int u, int v){
    int te = abs(dis[u] - dis[v]);
    return (te <= (dis[0] >> 1))? te : dis[0] - te;
}
void change(int ty, int po, int va){
    stk.emplace(ty, po, tr[ty][po]);
    tr[ty][po] = va;
}
void rb(){
    while(!stk.empty()){
        auto [ty, po, va] = stk.top(); stk.pop();
        tr[ty][po] = va;
    }
}
void ud(int ty, int po, int va, int ll = 1, int rr = N, int id = 1){
    if(ll == rr) return change(ty, id, va);
    int m = (ll + rr) >> 1;
    if(po <= m) ud(ty, po, va, ll, m, id << 1);
    else ud(ty, po, va, m + 1, rr, id << 1 | 1);
    change(ty, id, min(tr[ty][id << 1], tr[ty][id << 1 | 1]));
}
int gt(int ty, int l, int r, int ll = 1, int rr = N, int id = 1){
    if(l > rr or r < ll) return INF;
    if(l <= ll and r >= rr) return tr[ty][id];
    int m = (ll + rr) >> 1;
    return min(gt(ty, l, r, ll, m, id << 1), gt(ty, l, r, m + 1, rr, id << 1 | 1));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    fill_n(tr[0], X << 3, INF);
    fill_n(tr[1], X << 3, INF);
    cin >> N;
    for(int i = 0, u; i < N; ++i) cin >> u, ar[u].emplace_back(i? i : N), remax(mx, u);
    for(int i = 1; i <= N; ++i) {cin >> dis[i]; dis[i] += dis[i - 1];}
    for(int i = 1; i <= mx; ++i){
        for(int u: ar[i]) 
            dp[u] = (i == 1)? 0 : min(min(gt(0, 1, u - 1) + dis[u], gt(1, 1, u - 1) - dis[u] + dis[N]), min(gt(1, u + 1, N) - dis[u], gt(0, u + 1, N) + dis[u] + dis[N]));
        rb();
        // FIRST OF EVERY LEVEL -> O(qlogn) amortized nlogn
        if(ar[i].size() > 1){
            for(int u: ar[i]) ndp[u] = dp[u] + dis[N]; //amortized n
            for(int j = 0; j < ar[i].size(); ++j){ //amortized n
                int k = (j + 1) % ar[i].size();
                remin(ndp[ar[i][k]], dp[ar[i][j]] + ((dis[N] + dis[ar[i][j]] - dis[ar[i][k]]) % dis[N]));
            }
            for(int j = 0; j < ar[i].size(); ++j){ //amortized n
                int k = (j + 1) % ar[i].size();
                remin(ndp[ar[i][j]], dp[ar[i][k]] + ((dis[N] + dis[ar[i][k]] - dis[ar[i][j]]) % dis[N]));
            }
            for(int u: ar[i]) dp[u] = ndp[u], cout << dp[u]; //amortized n
        }
        for(int u: ar[i]) //amortized nlogn
            ud(0, u, dp[u] - dis[u]), ud(1, u, dp[u] + dis[u]);
    }
//    for(int i = 0; i <= N; ++i) cout << dp[i];
    for(int i: ar[mx]) remax(an, dp[i]);
    cout << an;
}