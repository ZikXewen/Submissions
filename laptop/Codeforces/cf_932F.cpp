#include <bits/stdc++.h>
#define long long long
using namespace std;

const long INF = 1e18;
const int HI = 1e5 + 5, X = 2e5 + 5;
struct line{
    long m, c;
    line(long _m, long _c) : m(_m), c(_c) {}
    long operator()(long x){return m * x + c;}
    void operator=(const line &r){m = r.m, c = r.c;}
};

int N, a[X], b[X];
long dp[X];
vector<line> tr[X], ls[X];
vector<int> g[X];

void add(vector<line> &tr, line nw){
    int l = 1, r = HI - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(nw(m) < tr[m](m)) swap(nw, tr[m]);
        if(nw(l) < tr[m](l)) r = m - 1;
        else if(nw(r) < tr[m](r)) l = m + 1;
        else break;
    }
}
long gt(vector<line> &tr, int x, long ret = INF){
    int l = 1, r = HI - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        ret = min(ret, tr[m](x));
        if(x < m) r = m - 1;
        else if (x > m) l = m + 1;
        else break;
    }
    return ret;
}

void dfs(int u, int p){
    if(g[u].empty()) {add(tr[u], line(b[u], 0)); return;}
    for(int &v: g[u]) if(v != p){ cout << v;
        dfs(v, u);
        if(g[v].size() > g[g[u][0]].size()) swap(v, g[u][0]);
    }
    swap(tr[u], tr[g[u][0]]); swap(ls[u], ls[g[u][0]]);
    for(int v = 1; v < g[u].size(); ++v) {
        for(line i: ls[v]) add(tr[u], i), ls[u].emplace_back(i);
        tr[v].clear();
    }
    add(tr[u], line(b[u], dp[u] = gt(tr[u], a[u])));
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> a[i];
    for(int i = 1; i <= N; ++i) cin >> b[i];
    for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
    dfs(1, 0);
    for(int i = 1; i <= N; ++i) cout << dp[i];
}