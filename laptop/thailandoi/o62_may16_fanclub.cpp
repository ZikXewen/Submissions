#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 2e5 + 5;
int N, M, A, B, id[X], go[X], mm[X], idm, rid[X];
bool mk[X];
vector<ii> g[X];
ii ri[X << 1], le[X << 1];
int dfs(int u, int p = 0, bool ret = 0){
    for(auto [v, w]: g[u]) if(v != p){
        int nx = dfs(v, u); 
        if(nx == -1) ret = 1, rid[id[u] = ++idm] = u, go[id[v]] = w; // Dist to next
        else mm[u] = max(mm[u], nx + w);
    }
    return (ret or u == B)? -1 : mm[u];
}
ii gt(const ii ar[], int u, int v, ii ret = ii(0, 0)){
    for(u += X, v += X + 1; u < v; u >>= 1, v >>= 1){
        if(u & 1) ret = max(ret, ar[u++]);
        if(v & 1) ret = max(ret, ar[--v]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    cin >> N >> M >> A >> B;
    for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    dfs(A);
    for(int i = 1; i < idm; ++i) ri[X + i + 1].first = ri[X + i].first + go[i];
    for(int i = idm; i; --i) le[X + i - 1].first = le[X + i].first + go[i - 1];
    int sm = ri[X + idm].first;
    for(int i = 0; i <= idm; ++i) 
        ri[X + i].first += mm[rid[i]], le[X + i].first += mm[rid[i]],
        ri[X + i].second = le[X + i].second = i;
    for(int i = X - 1; i; --i) // BUILD
        le[i] = max(le[i << 1], le[i << 1 | 1]),
        ri[i] = max(ri[i << 1], ri[i << 1 | 1]);
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v; if((u = id[u]) > (v = id[v])) swap(u, v);
        auto [ul, vl] = gt(le, u, v - 1); auto [ur, vr] = gt(ri, u + 1, v);
        cout << vl << ' ' << vr << '\n';
        cout << max(ul + gt(ri, vl + 1, v).first, ur + gt(le, u, vr - 1).first) - sm << '\n';
    }
}