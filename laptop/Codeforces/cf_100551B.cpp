#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 5e5 + 5, Y = 1e5 + 5;

int N, M, K, l[X];
bool an[Y];
ii g[Y];
vector<pair<int, ii>> rh[Y], lh[Y]; // [l, r)

struct one{
    int p[Y], cr;
    stack<ii> stk;

    one(){ iota(p, p + Y, 0), cr = 0; }
    int chn(int u, int v){
        stk.emplace(u, p[u]);
        return p[u] = v;
    }
    int fd(int u){return chn(u, p[u] == u? u : fd(p[u]));}
    bool un(ii nw){
        auto [u, v] = nw; u = fd(u), v = fd(v);
        if(u == v) return 0;
        chn(u, v);
        ++cr;
        return 1;
    }
    void rb(int va){
        while(stk.size() > va){
            auto [u, v] = stk.top(); stk.pop(); p[u] = v;
        }
    }
    void bd(int l, int r){
        if(l == r) return void(an[l] = (cr == N - 1));
        int torb = stk.size(), tocr = cr;
        int m = (l + r) >> 1;
        for(int i = l; i <= m; ++i) for(auto [u, va]: lh[i]) if(u >= r) un(va);
        bd(l, m);
        cr = tocr; rb(torb);
        for(int i = m + 1; i <= r; ++i) for(auto [u, va]: rh[i]) if(u <= l) un(va);
        bd(m + 1, r);
        cr = tocr; rb(torb);
    }
} dsu;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    fill(l, l + M + 1, 1);
    for(int i = 1, u, v; i <= M; ++i) cin >> u >> v, g[i] = ii(u, v);
    cin >> K;
    for(int i = 1, u; i <= K; ++i) {
        cin >> u;
        for(int j = 0, v; j < u; ++j) {
            cin >> v;
            if(l[v] == i) ++l[v];
            else lh[l[v]].emplace_back(i - 1, g[v]), rh[i - 1].emplace_back(l[v], g[v]), l[v] = i + 1;
        }
    }
    for(int i = 0; i < N; ++i) if(l[i])
        lh[l[i]].emplace_back(K, g[i]), rh[K].emplace_back(l[i], g[i]);
    dsu.bd(1, K);
    for(int i = 0; i < K; ++i) cout << an[i];
}