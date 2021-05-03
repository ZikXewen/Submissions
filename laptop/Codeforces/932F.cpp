#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int X = 1e5 + 5;
const int64 INF = 1e18;
struct pnt{
    int64 u, v;
    int64 operator()(int x){return u * x + v;}
    pnt(int64 _u, int64 _v) : u(_u), v(_v) {}
};
struct node{
    pnt va;
    node *l, *r;
    int lo, hi;
    vector<pnt> mem;
    void add(pnt u){
        int m = (lo + hi) >> 1;
        if(u(m) < va(m)) swap(u, va);
        if(lo == hi) return;
        if((u(lo) < va(lo)) == (u(m) < va(m))){
            if(!r) r = new node(m + 1, hi);
            r -> add(u);
        } else {
            if(!l) l = new node(lo, m);
            l -> add(u);
        }
    }
    int64 gt(int u){
        node *nx = ((u <= (lo + hi) >> 1)? l : r);
        return min(va(u), (nx? nx -> gt(u) : INF));
    }
    void addE(pnt u){ mem.emplace_back(u); add(u); }
    node(int _lo, int _hi) : lo(_lo), hi(_hi), va(0, INF), l(), r(), mem() {}
} *tr[X];
int N, ar1[X], ar2[X], sz[X];
int64 ans[X];
vector<int> g[X];
void sol(int u = 1, int p = 0){
    sz[u] = 1; int pc = 0;
    for(auto v: g[u]) if(v != p) {
        sol(v, u);
        sz[u] += sz[v];
        if(!pc or sz[v] > sz[pc]) pc = v;
    }
    if(!pc) return (tr[u] = new node(-X, X)) -> addE(pnt(ar2[u], 0)), void();
    swap(tr[u], tr[pc]);
    for(auto v: g[u]) if(v != p and v != pc) for(auto i: tr[v] -> mem) tr[u] -> addE(i);
    ans[u] = tr[u] -> gt(ar1[u]);
    tr[u] -> addE(pnt(ar2[u], ans[u]));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> ar1[i];
    for(int i = 1; i <= N; ++i) cin >> ar2[i];
    for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
    sol();
    for(int i = 1; i <= N; ++i) cout << ans[i] << ' ';
}