#include <bits/stdc++.h>
#define int64 long long
using namespace std;
const int HI = 1e5 + 5, LHI = 350;
const int64 INF = LLONG_MAX;
struct line{
    int64 u, v, w, z;
    line(int64 _u, int64 _v, int64 _w, int64 _z) : u(_u), v(_v), w(_w), z(_z) {}
    int64 operator()(int64 x){return u + (x * (v + (x * (w + (x * z)))));}
};
struct node{
    line va;
    node *l, *r;
    int lo, hi;
    node(int _l, int _r) : lo(_l), hi(_r), va(INF, 0, 0, 0), l(0), r(0) {}
    void add(line u){
        int m = (lo + hi) >> 1;
        if(u(m) < va(m)) swap(u, va);
        if(lo != hi) ((u(lo) < va(lo)) != (u(m) < va(m))? l : r) -> add(u);
    }
    int64 gt(int x){
        if(lo == hi) return va(x);
        return min(va(x), ((x <= (lo + hi) >> 1)? l : r) -> gt(x));
    }
    void bd(){
        if(lo == hi) return;
        int m = (lo + hi) >> 1;
        l = new node(lo, m); l -> bd();
        r = new node(m + 1, hi); r -> bd();
    }
    void del(){
        if(lo != hi) l -> del(), r -> del();
        delete this;
    }
} *tr;

int T, N, Q;
int64 gtl[LHI];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while(T--){
        fill_n(gtl, LHI, INF);
        tr = new node(LHI, HI); tr -> bd();
        cin >> N;
        for(int i = 0, u, v, w, z; i < N; ++i){
            cin >> u >> v >> w >> z;
            line tem(u, v, w, z);
            for(int j = 0; j < LHI; ++j) gtl[j] = min(gtl[j], tem(j));
            tr -> add(tem);
        }
        cin >> Q;
        for(int i = 0, u; i < Q; ++i){
            cin >> u; 
            cout << (u < LHI? gtl[u] : tr -> gt(u)) << '\n';
        }
        tr -> del();
    }
}