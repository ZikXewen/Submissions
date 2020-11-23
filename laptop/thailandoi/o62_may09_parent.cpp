#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5, LX = 19;
int N, M, p[X], hd[X], pre[X][LX], lvl[X];
vector<int> g[X];
void dfs(int u, int pa){
    pre[u][0] = pa; lvl[u] = lvl[pa] + 1;
    for(int i = 1; i < LX; ++i) pre[u][i] = pre[pre[u][i - 1]][i - 1];
    for(int v: g[u]) if(v != pa) dfs(v, u);
}
int fd(int x){return p[x] < 0? x : (p[x] = fd(p[x]));}
void mrg(int u, int v){
    int uu = fd(u), vv = fd(v);
    hd[uu] = hd[vv];
    if(p[uu] < p[vv]) swap(u, v), swap(uu, vv); // size u now < v
    p[vv] += p[uu]; p[uu] = vv;
    g[u].emplace_back(v); g[v].emplace_back(u); 
    dfs(u, v);
}
int dis(int u){
    int v = hd[fd(u)], ret = 0;
    if(lvl[u] < lvl[v]) swap(u, v); // depth u now > v
    for(int i = LX - 1; i >= 0; --i) if(lvl[pre[u][i]] >= lvl[v]) u = pre[u][i], ret += (1 << i);
    if(u == v) return ret;
    for(int i = LX - 1; i >= 0; --i) if(pre[u][i] != pre[v][i]) u = pre[u][i], v = pre[v][i], ret += (1 << (i + 1));
    return ret + 2;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) p[i] = -1, hd[i] = i, lvl[i] = 1;
    for(int i = 0, u, v, w; i < M; ++i){
        cin >> w >> u;
        if(w == 2) hd[fd(u)] = u; else cin >> v;
        if(w == 1) mrg(u, v);
        if(w == 3) cout << (dis(u) < dis(v)? u : v) << '\n';
    }
}