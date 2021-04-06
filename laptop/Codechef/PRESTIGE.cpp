#include<bits/stdc++.h>
using namespace std;
int N, M, mrk;
class one{
public:
    int va, pri, sz;
    long long sm;
    bool rv;
    one *l, *r;
    one(int _va) : va(_va), pri(rand()), sz(1), sm(_va), rv(0), l(), r() {}
} *tr1, *tr2;
int _sz(one *u){return u? u -> sz : 0;}
long long _sm(one *u){return u? u -> sm : 0;}
void ps(one *u){
    if(!u or !(u -> rv)) return;
    u -> rv = 0;
    swap(u -> l, u -> r);
    if(u -> l) u -> l -> rv ^= 1;
    if(u -> r) u -> r -> rv ^= 1;
}
void ud(one *u){
    if(!u) return;
    u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
    u -> sm = _sm(u -> l) + _sm(u -> r) + u -> va;
}
void spl(one *u, one *&l, one *&r, int va){
    if(!u) return( l = r = NULL), void();
    ps(u);
    if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, va), r = u;
    ud(u);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) return (u = (l? l : r)), void();
    ps(l), ps(r);
    if(l -> pri < r -> pri) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
    cin >> N >> M;
    for(int i = 0, u; i < N; ++i) cin >> u, mrg(tr1, new one(u), tr1);
    for(int i = 0, u; i < N; ++i) cin >> u, mrg(tr2, new one(u), tr2);
    for(int i = 0, u, v, w, z; i < M; ++i){
        cin >> u;
        if(u == 1){
            cin >> v >> w;
            one *a1, *a2, *b1, *b2;
            spl(tr1, tr1, b1, w); spl(tr2, tr2, b2, w);
            spl(tr1, tr1, a1, v - 1); spl(tr2, tr2, a2, v - 1);
            if(a1) a1 -> rv ^= 1;
            if(a2) a2 -> rv ^= 1;
            mrg(tr1, a2, tr1); mrg(tr1, b1, tr1);
            mrg(tr2, a1, tr2); mrg(tr2, b2, tr2);
        } else if(u == 2){
            cin >> v;
            mrk = v - mrk;
        } else {
            cin >> w >> z >> u >> v;
            int sp = min(max(mrk - u, -1), v - u);
            one *a, *b, *c;
            spl(tr1, tr1, c, z); spl(tr1, tr1, b, w + sp); spl(tr1, tr1, a, w - 1);
            cout << _sm(b) - _sm(a) << '\n';
            mrg(tr1, a, tr1); mrg(tr1, b, tr1); mrg(tr1, c, tr1);
        }
    }
}