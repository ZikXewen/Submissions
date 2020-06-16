#include <bits/stdc++.h>
using namespace std;
struct one{
    int va, pri, sz;
    bool rv;
    one *l, *r;
    one(int _va) : va(_va), pri(rand()), sz(1), rv(0), l(0), r(0) {}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
void mk(one *&u){if(u) u -> rv ^= 1;}
void ps(one *&u){if(u -> rv) u -> rv = 0, swap(u -> l, u -> r), mk(u -> l), mk(u -> r);}
void ud(one *&u){u -> sz = _sz(u -> l) + _sz(u -> r) + 1;}
void spl(one *u, one *&l, one *&r, int po){
    if(!u){l = r = 0; return;}
    ps(u);
    if(_sz(u -> l) < po) spl(u -> r, u -> r, r, po - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, po), r = u;
    ud(u);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r){u = l? l : r; return;}
    ps(l); ps(r);
    if(l -> pri < r -> pri) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}

int N, Q, M;
vector<int> an;

void prnt(one *u = tr){
    if(!u) return;
    ps(u); prnt(u -> l); an.emplace_back(u -> va); prnt(u -> r);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    srand(time(0));
    cin >> N >> Q >> M;
    for(int i = 0, u; i < N; ++i) cin >> u, mrg(tr, new one(u), tr);
    for(int i = 0, u, v, w; i < Q; ++i){
        cin >> u >> v >> w;
        if(u == 1){
            one *l, *ex, *r; // l tr ex r
            spl(tr, tr, r, w); spl(tr, tr, ex, w - 1); spl(tr, l, tr, v - 1);
            mrg(l, ex, l); mrg(l, tr, tr); mrg(tr, r, tr);
        } else {
            one *l, *r;
            spl(tr, tr, r, w); spl(tr, l, tr, v - 1);
            mk(tr); mrg(l, tr, tr); mrg(tr, r, tr);
        }
    }
    prnt();
    for(int i = 0, u; i < M; ++i) cin >> u, cout << an[u - 1] << ' ';
}