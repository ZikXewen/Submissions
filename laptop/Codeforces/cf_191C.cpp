#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, mk[X][20], p[X][20], lv[X], id[X];
vector<int> g[X];
vector<pair<int, int>> ed;
void dfs(int u){
    lv[u] = lv[p[u][0]] + 1;
    for(int i = 1; i < 20; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
    for(int v: g[u]) if(v != p[u][0]) p[v][0] = u, dfs(v);
}
void lca(int u, int v){
    if(lv[u] < lv[v]) swap(u, v);
    for(int i = 19; i >= 0; --i) if(lv[p[u][i]] >= lv[v]) ++mk[u][i], u = p[u][i];
    if(u == v) return;
    for(int i = 19; i >= 0; --i) if(p[u][i] != p[v][i]) ++mk[u][i], ++mk[v][i], u = p[u][i], v = p[v][i];
    ++mk[u][0], ++mk[v][0];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u), ed.emplace_back(u, v);
    dfs(1);
    for(int i = 0; i < N - 1; ++i){
        auto [u, v] = ed[i];
        id[i] = (lv[u] < lv[v])? v : u;
    } 
    cin >> M;
    for(int i = 0, u, v; i < M; ++i) cin >> u >> v, lca(u, v);
    for(int i = 19; i; --i) for(int u = 0; u <= N; ++u) mk[u][i - 1] += mk[u][i], mk[p[u][i - 1]][i - 1] += mk[u][i];
    for(int i = 0; i < N - 1; ++i) cout << mk[id[i]][0] << ' ';
}