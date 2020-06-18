#include <bits/stdc++.h>

using namespace std;
const int X = 1e5 + 5;
const double INF = 1e9 + 5;
int N, M, st[X];
int tr[6][X * 6], lz[6][X * 6];
void minn(int &u, int v){u = min(u, v);}
void ud(int l, int r, int va, int no, int ll = 0, int rr = N - 1, int id = 1){
    if(l > rr or r < ll) return;
    if(lz[no][id] != INF){
        minn(tr[no][id], lz[no][id]);
        if(ll != rr)
            minn(lz[no][id << 1], lz[no][id]),
            minn(lz[no][id << 1 | 1], lz[no][id]);
        lz[no][id] = INF;
    }
    if(l <= ll and r >= rr){
        minn(tr[no][id], va);
        if(ll != rr)
            minn(lz[no][id << 1], va),
            minn(lz[no][id << 1 | 1], va);
        return;
    }
    int m = (ll + rr) >> 1;
    ud(l, r, va, no, ll, m, id << 1);
    ud(l, r, va, no, m + 1, rr, id << 1 | 1);
    tr[no][id] = min(tr[no][id << 1], tr[no][id << 1 | 1]);
}
int gt(int x, int no, int l = 0, int r = N - 1, int id = 1){
    if(lz[no][id] != INF){
        minn(tr[no][id], lz[no][id]);
        if(l != r)
            minn(lz[no][id << 1], lz[no][id]),
            minn(lz[no][id << 1 | 1], lz[no][id]);
        lz[no][id] = INF;
    }
    if(l == r) return tr[no][id];
    int m = (l + r) >> 1;
    if(x <= m) return gt(x, no, l, m, id << 1);
    return gt(x, no, m + 1, r, id << 1 | 1);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < 6; ++i)
        fill_n(tr[i], N * 6, INF),
        fill_n(lz[i], N * 6, INF);
    for(int i = 0; i < N; ++i) cin >> st[i];
    for(int i = 0, u, v, w, x, y; i < M; ++i){
        cin >> u >> v >> w >> x >> y;
        for(int i = 1; i <= min(5, y/(v - 1)); ++i) ud(w, x, y, i); //l, r, va, no
    }
    for(int i = 0; i < N; ++i){
        int te = gt(i, st[i]);
        cout << ((te == INF)? (int)1e8 * st[i] : te) << '\n';
    }
}