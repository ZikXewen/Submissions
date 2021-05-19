#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct one{
    int va, pr, sz;
    one *l, *r;
    one(int _va) : va(_va), pr(rng()), sz(1), l(), r() {}
} *tr;
int N, M, ans[X];
bool usedno[X];
int _sz(one *u){return u? u -> sz : 0;}
void ud(one *u){if(u) u -> sz = _sz(u -> l) + _sz(u -> r) + 1;}
void spl(one *u, one *&l, one *&r, int va){
    if(!u) return l = r = nullptr, void();
    if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
    else spl(u -> l, l, u -> l, va), r = u;
    ud(l), ud(r);
}
void mrg(one *l, one *r, one *&u){
    if(!l or !r) return u = (l? l : r), void();
    if(l -> pr < r -> pr) mrg(l -> r, r, l -> r), u = l;
    else mrg(l, r -> l, r -> l), u = r;
    ud(u);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) mrg(tr, new one(i), tr);
    for(int i = 0, u, v; i < M; ++i){
        one *l, *r;
        cin >> u >> v;
        spl(tr, l, tr, v - 1), spl(tr, tr, r, 1);
        int &k = ans[tr -> va];
        if((k and k != u) or(!k and usedno[u])) return cout << -1, 0;
        usedno[k = u] = 1;
        mrg(tr, l, tr), mrg(tr, r, tr);
    }
    auto nx = [=](){
        static int ct = 1;
        while(usedno[ct]) ++ct;
        usedno[ct] = 1;
        return ct;
    };
    for(int i = 1; i <= N; ++i) cout << (ans[i]? ans[i] : nx()) << ' ';
}