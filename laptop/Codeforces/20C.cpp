#include <bits/stdc++.h>
#define long long long
using namespace std;
typedef pair<long, long> ii;
int N, M;
priority_queue<ii> q;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<vector<ii>> g(N + 1);
    vector<long> dis(N + 1, -1e12);
    vector<int> pa(N + 1), ans;
    for(int i = 0, u, v, w; i < M; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    q.emplace(0, 1); dis[1] = 0;
    while(q.size()){
        auto [u, v] = q.top(); q.pop();
        if(dis[v] != u) continue;
        for(auto [w, x]: g[v]) if(dis[v] - x > dis[w]) q.emplace(dis[w] = dis[v] - x, w), pa[w] = v;
    }
    if(!pa[N]) return cout << -1, 0;
    do ans.emplace_back(N); while(N = pa[N]);
    reverse(ans.begin(), ans.end());
    for(int i: ans) cout << i << ' ';
}