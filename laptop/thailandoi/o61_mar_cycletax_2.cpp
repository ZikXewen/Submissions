#include <bits/stdc++.h>
using namespace std;
const int X = 1e4 + 5;
int N, M, su, sv, sw;
bool mm[X];
vector<int> g[X];
vector<pair<int, int>> an;
bool dfs(int u, int p){
    mm[u] = 1;
    for(int v: g[u]) if(v != p){
        if(mm[v] == 2) 
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v, w; i < M; ++i) {
        cin >> u >> v >> w, g[u].emplace_back(v), g[v].emplace_back(u);
        if(w < sw) su = u, sv = v, sw = w;
    }
    g[su].erase(find(g[su].begin(), g[su].end(), sv));
    g[sv].erase(find(g[sv].begin(), g[sv].end(), su));
    dfs(su, sv); cout << sv << su << 1;
    for(auto [u, v]: an) cout << u << v << "0\n";
}