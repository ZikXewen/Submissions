#include <bits/stdc++.h>
#define int64 long long
using namespace std;
const int HI = 1e5 + 5;
const int64 INF = LLONG_MAX;
struct line{
    int64 u, v, w, z;
    line(int64 _u, int64 _v, int64 _w, int64 _z) : u(_u), v(_v), w(_w), z(_z) {}
    int64 operator()(int64 x){return u + (x * (v + (x * (w + (x * z)))));}
};
struct node{
    line va;
    node *l, *r;
    int64 lo, hi;
    node(int _l, int _r) : lo(_l), hi(_r), va(INF, 0, 0, 0), l(0), r(0) {}
    void add(line u){
        int m = (lo + hi) >> 1;
        if(u(m) < va(m)) swap(u, va);
        if(lo + 1 == hi) return;
        if(u(lo) < va(lo)){
            if(!l) l = new node(lo, m);
            l -> add(u);
        }
        else {
            if(!r) r = new node(m, hi);
            r -> add(u);
        }
    }
    int64 gt(int x){
        int64 ret = va(x);
        if(x < (lo + hi) >> 1) {if(l) return min(ret, l -> gt(x));}
        else {if(r) return min(ret, r -> gt(x));}
        return ret;
    }
};


int T, N, Q;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while(T--){
        node *tr = new node(0, HI);
        cin >> N;
        for(int i = 0, u, v, w, z; i < N; ++i) cin >> u >> v >> w >> z, tr -> add(line(u, v, w, z));
        cin >> Q;
        for(int i = 0, u; i < Q; ++i) cin >> u, cout << tr -> gt(u) << '\n';
    }
}