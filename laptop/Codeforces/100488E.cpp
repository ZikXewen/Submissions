#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, M, K, Q;
struct one{
    char va;
    int prio, sz;
    bool mr;
    one *l, *r;
    one(char _va) : va(_va), prio(rng()), sz(1), mr(), l(), r() {}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
void ud(one *u){
    if(!u) return;
    u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
}
void pus(one *u){
    if(!u or !(u -> mr)) return;
    u -> mr = 0;
    swap(u -> l, u -> r);
    if(u -> l) u -> l -> mr ^= 1;
    if(u -> r) u -> r -> mr ^= 1;
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) return u = (l? l : r), void();
    pus(l), pus(r);
    if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}
void spl(one *u, one *&l, one *&r, int po){
    if(!u) return l = r = nullptr, void();
    pus(u);
    if(_sz(u -> l) < po) spl(u -> r, u -> r, r, po - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, po), r = u;
    ud(l), ud(r);
}
void pt(one *u){
    if(!u) return;
    pus(u);
    pt(u -> l); cout << u -> va; pt(u -> r);
}
string str;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K >> str >> Q;
    for(auto i: str) mrg(tr, new one(i), tr);
    char u, v, w;
    for(int i = 0; i < Q; ++i){
        cin >> u;
        if(u == 'S'){
            cin >> v >> w;
            (v == 'L'? M : K) += (w == 'L'? -1 : 1);
        }
        else if(u == 'R'){
            one *l, *r;
            spl(tr, tr, r, K); spl(tr, l, tr, M - 1);
            if(tr) tr -> mr ^= 1;
            mrg(l, tr, tr); mrg(tr, r, tr);
        }
        else{
            cin >> v;
            one *l, *r;
            spl(tr, tr, r, v == 'L'? M : K); spl(tr, l, tr, (v == 'L'? M : K) - 1);
            cout << tr -> va;
            mrg(l, tr, tr); mrg(tr, r, tr);
        }
    }
}
/*
11 2 6
abracadabra
12
Q L
Q R
R
Q L
Q R
S L R
S R R
Q L
Q R
R
Q L
Q R
*/