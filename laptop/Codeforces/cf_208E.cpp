#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, p[X][20], ct, id[X], lv[X], ls[X];
vector<int> g[X], cd[X];
void dfs(int u){
    for(int i = 1; i <= 19; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
    cd[lv[u] = lv[p[u][0]] + 1].emplace_back(id[u] = ++ct);
    for(int v: g[u]) p[v][0] = u, dfs(v);
    ls[u] = ct;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> p[i][0], g[p[i][0]].emplace_back(i);
    dfs(0);
    cin >> M;
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        int lvl = lv[u];
        for(int j = 0; v; v >>= 1, ++j) if(v & 1) u = p[u][j];
        if(!u) cout << 0 << '\n';
        else cout << upper_bound(cd[lvl].begin(), cd[lvl].end(), ls[u]) - lower_bound(cd[lvl].begin(), cd[lvl].end(), id[u]) - 1 << '\n';
    }
}