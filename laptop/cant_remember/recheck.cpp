#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 2e5 + 5;
int N, M, P, Q, l[X], dmg[X], h[X], hp[X], ct, pa[X], st[X];
long dlt[X], cr;
bool stat[X];
int fd(int x){return (pa[x] >= 0)? pa[x] = fd(pa[x]) : x;}
void un(int v){
    int u = fd(v - 1);
    cr += 0ll + dmg[-pa[u] - pa[v]] - dmg[-pa[u]] - dmg[-pa[v]];
    pa[u] += pa[v], pa[v] = u;
}
void add(const int &po){
    stat[po] = 1;
    if(stat[po - 1]) un(po);
    if(stat[po + 1]) un(po + 1);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> P >> Q;
    for(int i = 0; i < N; ++i) cin >> l[i];
    for(int i = 0; i < M; ++i) cin >> dmg[i + 2];
    for(int i = 0; i < P; ++i) cin >> h[i];
    for(int i = 0; i < Q; ++i) cin >> hp[i];
    iota(st, st + N, 0);
    sort(st, st + N, [](const int &u, const int &v){return l[u] > l[v];});
    memset(pa, -1, sizeof pa);
    for(int i = 0; i < P; ++i){
        while(ct < N and l[st[ct]] >= h[i]) add(st[ct++]);
        dlt[i] = dlt[max(i - 1, 0)] + cr;
    }
    for(int i = 0; i < Q; ++i){
        int an = lower_bound(dlt, dlt + P, hp[i]) - dlt + 1;
        cout << (an > P? -1 : an) << ' ';
    }
}