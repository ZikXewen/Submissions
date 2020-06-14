#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e5 + 5;

vector<pair<int, ii>> rh[X], lh[X];

struct one{
    int cr;
    vector<int> p;
    vector<bool> an;
    stack<ii> stk;

    one(int _sz, int _sa) : p(vector<int>(_sz + 1, -1)), cr(0), an(vector<bool>(_sa + 1)) {}
    int chn(int u, int v){
        stk.emplace(u, p[u]);
        return p[u] = v;
    }
    int fd(int u){return p[u] < 0? u : fd(p[u]);}
    bool un(ii nw){
        auto [u, v] = nw; u = fd(u), v = fd(v);
        if(u == v) return 0;
        if(p[u] < p[v]) swap(u, v);
        chn(v, p[v] + p[u]); chn(u, v);
        ++cr;
        return 1;
    }
    void rb(int va){
        while(stk.size() > va){
            auto [u, v] = stk.top(); stk.pop(); p[u] = v;
        }
    }
    void bd(int l, int r){
        if(l == r) return void(an[l] = (cr == p.size() - 2));
        int torb = stk.size(), tocr = cr;
        int m = (l + r) >> 1;
        for(int i = l; i <= m + 1; ++i) for(auto [u, va]: lh[i]) if(u >= r) un(va);
        bd(m + 1, r);
        cr = tocr; rb(torb);
        for(int i = m; i <= r; ++i) for(auto [u, va]: rh[i]) if(u <= l) un(va);
        bd(l, m);
        cr = tocr; rb(torb);
    }
    void prt(){ for(int i = 1; i < an.size(); ++i) cout << (an[i]? "Connected" : "Disconnected") << '\n';}
};

int N, M, K, l[X];
ii g[X];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("disconnected.in", "r", stdin);
    freopen("disconnected.out", "w", stdout);
    cin >> N >> M;
    fill(l, l + M + 1, 1);
    for(int i = 1, u, v; i <= M; ++i) cin >> u >> v, g[i] = ii(u, v);
    cin >> K;
    one dsu = one(N, K);
    for(int i = 1, u; i <= K; ++i) {
        cin >> u;
        for(int j = 0, v; j < u; ++j) {
            cin >> v;
            if(l[v] == i) ++l[v];
            else lh[l[v]].emplace_back(i - 1, g[v]), rh[i - 1].emplace_back(l[v], g[v]), l[v] = i + 1;
        }
    }
    for(int i = 1; i <= M; ++i) if(l[i] <= K)
        lh[l[i]].emplace_back(K, g[i]), rh[K].emplace_back(l[i], g[i]);
    dsu.bd(1, K);
    dsu.prt();
}