#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
const int X = 1e4 + 5, INF = 1e9 + 5;
int V, E, S, T, m1 = INF, m2 = INF;
vector<vector<ii>> g, rg;
vector<int> d, rd;
vector<iii> el;
void dfs(int st, const vector<vector<ii>> ed, vector<int> &dis){
    dis.assign(ed.size(), -1);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.emplace(0, st);
    while(q.size()){
        auto [w, u] = q.top(); q.pop();
        if(dis[u] != -1) continue;
        dis[u] = w;
        for(auto [v, vw]: ed[u]) if(dis[v] == -1) q.emplace(w + vw, v);
    }
}
int main(){
    cin >> V >> E >> S >> T;
    g.resize(V + 1), rg.resize(V + 1);
    for(int i = 0, u, v, w; i < E; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), rg[v].emplace_back(u, w), el.emplace_back(u, v, w);
    dfs(S, g, d); dfs(T, rg, rd);
    for(auto [u, v, w]: el){
        int cr = w + d[u] + rd[v];
        if(cr < m1) m2 = m1, m1 = cr;
        else if(cr != m1 and cr < m2) m2 = cr;
    }
    cout << m2;
}