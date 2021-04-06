#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, v[X];
stack<int> stk;
class one{
public:
    int va, pri, sz;
    one *l, *r;
    one(int _va) : sz(1), va(_va), pri(rand()), l(), r() {}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
void ud(one *u){
    if(!u) return;
    u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
}
void spv(one *u, one *&l, one *&r, int va){
    if(!u) return (l = r = NULL), void();
    if(u -> va < va) spv(u -> r, u -> r, r, va), l = u;
    else spv(u -> l, l, u -> l, va), r = u;
    ud(u);
}
void spl(one *u, one *&l, one *&r, int va){
    if(!u) return (l = r = NULL), void();
    if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, va), r = u;
    ud(u);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) return (u = (l? l : r)), void();
    if(l -> pri < r -> pri) mrg(l, r -> l, r -> l), u = r;
    else mrg(l -> r, r, l -> r), u = l;
    ud(u);
}
void add(int x){
    one *r, *nw = new one(x);
    spv(tr, tr, r, x); mrg(tr, nw, tr); mrg(tr, r, tr);
}
void get(int x){
    one *l, *r;
    spl(tr, tr, r, x); spl(tr, l, tr, x - 1);
    stk.emplace(tr -> va);
    mrg(l, r, tr);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
    cin >> N;
    for(int i = 0, u; i < N; ++i) cin >> u, add(u);
    for(int i = 1; i <= N; ++i) cin >> v[i], ++v[i];
    for(int i = N; i; --i) get(v[i]);
    while(stk.size()) cout << stk.top() << '\n', stk.pop();
}