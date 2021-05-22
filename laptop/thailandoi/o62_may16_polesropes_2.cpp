#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M;
struct node{
    int l, r, va;
    bool mk;
    node *ll, *rr;
    node(int _l, int _r) : l(_l), r(_r), va(), mk(), ll(), rr(){
        if(l == r) {va = 10; return;}
        int m = (l + r) >> 1;
        va = (ll = new node(l, m)) -> va + (rr = new node(m + 1, r)) -> va;
    }
    void ps(){
        if(!mk) return;
        va = mk = 0;
        if(l != r) ll -> mk = rr -> mk = 1;
    }
    int que(int u, int v){
        ps();
        if(u > r or v < l or u > v) return 0;
        if(u <= l and v >= r) return va;
        return ll -> que(u, v) + rr -> que(u, v);
    }
    void rud(int u, int v){ 
        ps();
        if(u > r or v < l or u > v) return;
        if(u <= l and v >= r) return mk = 1, ps();
        ll -> rud(u, v), rr -> rud(u, v);
        va = ll -> va + rr -> va;
    }
    void ud(int u, int v){
        ps();
        if(l != r) ((u <= ((l + r) >> 1))? ll : rr) -> ud(u, v);
        va += v;
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    node *tr = new node(1, --N);
    auto pul = [&](int u, int po){
        int l = 1, r = u + 1; // Offset R by 1 so bsearch works
        while(l < r){
            int m = (l + r) >> 1;
            if(tr->que(m, u) <= po) r = m;
            else l = m + 1;
        }
        --l;
        tr->ud(l, tr->que(l + 1, u) - po);
        tr->rud(l + 1, u);
    };
    auto pur = [&](int u, int po){
        int l = u, r = N;
        while(l < r){
            int m = (l + r) >> 1;
            if(tr->que(u, m) >= po) r = m;
            else l = m + 1;
        }
        tr->ud(r, tr->que(u, r - 1) - po);
        tr->rud(u, r - 1);
    };
    for(int i = 0, ty, u, v; i < M; ++i){
        cin >> ty >> u;
        if(ty == 1){
            cin >> v;
            int sl = tr->que(1, u - 1), sr = tr->que(u + 1, N);
            if(sl <= (v >> 1)) tr->rud(1, u - 1), pur(u + 1, v - sl);
            else if(sr <= (v >> 1)) tr->rud(u + 1, N), pul(u - 1, v - sr);
            else pul(u - 1, v >> 1), pur(u + 1, v >> 1);
            tr->ud(u, v);
        } 
        else cout << tr->que(u, u) << '\n';
    }
}
//TLE