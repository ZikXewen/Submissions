#include <bits/stdc++.h>
using namespace std;
const int X = 3e5 + 5;
struct one{
    int va, sz, prio; bool rv;
    one *l, *r;
    one(int _va) : va(_va), sz(1), prio(rand()), rv(0), l(0), r(0) {}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
void pus(one *u){ 
    if(!u -> rv) return;
    u -> rv = 0;
    swap(u -> l, u -> r);
    if(u -> l) u -> l -> rv ^= 1;
    if(u -> r) u -> r -> rv ^= 1;
}
void ud(one *u){ u -> sz = _sz(u -> l) + _sz(u -> r) + 1; }
int N, ar[X], te;
int gt(one *u, int po){
    if(!u) return -1;
    pus(u);
    if(_sz(u -> l) == po) return u -> va;
    if(_sz(u -> l) < po) return gt(u -> r, po - _sz(u -> l) - 1);
    else return gt(u -> l, po);
}
void spl(one *u, one *&l, one *&r, int po){
    if(!u) {l = r = 0; return;}
    pus(u);
    if(_sz(u -> l) < po) spl(u -> r, u -> r, r, po - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, po), r = u;
    ud(u);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) {u = l? l : r; return;}
    pus(l), pus(r);
    if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}
void rev(one *&u, int po){
    if(!u) return;
    one *r = 0;
    spl(u, u, r, po);
    u -> rv ^= 1;
    mrg(u, r, u);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
    cin >> N; for(int i = 0, u; i < N; ++i) cin >> u, mrg(tr, new one(u), tr);
    for(int i = 0;; ++i){
        int te = gt(tr, 0);
        if(te == 1) {cout << i; return 0;}
        rev(tr, te);
    }
}