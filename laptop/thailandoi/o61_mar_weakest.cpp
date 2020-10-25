#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 1e5 + 5, Y = 20, INF = INT_MAX;
int N, d[X][Y], p[X][Y], lv[X];
long q, k, m, a1, a2, ri;
int que(int u, int v){
    int ret = INF;
    if(lv[u] < lv[v]) swap(u, v);
    for(int i = log2(N); i >= 0; --i) 
        if(lv[p[u][i]] >= lv[v]) 
            ret = min(ret, d[u][i]),
            u = p[u][i];
    if(u == v) return ret;
    for(int i = log2(N); i >= 0; --i) 
        if(p[u][i] != p[v][i]) 
            ret = min(ret, min(d[u][i], d[v][i])),
            u = p[u][i], v = p[v][i];
    return min(ret, min(d[u][0], d[v][0]));
}
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; ++i) fill_n(d[i], Y, INF);
    for(int i = 1; i < N; ++i) {
        cin >> p[i][0] >> d[i][0];
        lv[i] = lv[p[i][0]] + 1;
        for(int j = 1; j <= log2(N); ++j)
            p[i][j] = p[p[i][j - 1]][j - 1],
            d[i][j] = min(d[i][j - 1], d[p[i][j - 1]][j - 1]);
    }
    cin >> q >> k >> m >> a1 >> a2; 
    while(q--){
        cout << (ri = que(a1, a2) % INF) << '\n';
        a1 = a2;
        a2 = (a2 * k + ri) % m % N;
    }
}