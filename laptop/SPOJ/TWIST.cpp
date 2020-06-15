#include <bits/stdc++.h>
using namespace std;
int N, M;
struct one{
    int va, sz, pri; bool rv;
    one *l, *r;
    one(int _va) : va(_va), sz(1), pri(rand()), rv(0), l(0), r(0) {}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
void _mk(one *&u){if(u) u -> rv ^= 1;}
void ps(one *&u){if(u -> rv) u -> rv = 0, swap(u -> l, u -> r), _mk(u -> l), _mk(u -> r);}
void ud(one *&u){if(u) u -> sz = _sz(u -> l) + _sz(u -> r) + 1;}
void spl(one *u, one *&l, one *&r, int po){
    if(!u) {l = r = 0; return;}
    ps(u);
    if(_sz(u -> l) < po) spl(u -> r, u -> r, r, po - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, po), r = u;
    ud(u);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) {u = l? l : r; return;}
    ps(l); ps(r);
    if(l -> pri < r -> pri) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}
void rev(int u, int v){
    one *l, *r;
    spl(tr, tr, r, v); spl(tr, l, tr, u - 1);
    _mk(tr);
    mrg(l, tr, tr); mrg(tr, r, tr);
}
void prt(one *u = tr){
    if(!u) return;
    ps(u); prt(u -> l);
    cout << u -> va << ' ';
    prt(u -> r);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) mrg(tr, new one(i), tr);
    for(int i = 0, u, v; i < M; ++i) cin >> u >> v, rev(u, v);
    prt();
}