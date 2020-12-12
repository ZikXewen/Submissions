#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5 ;
int N, M, tr[X << 2]; 
bool lz[X << 2];
void pus(int id, bool nx){
    if(!lz[id]) return;
    tr[id] = lz[id] = 0; 
    if(nx) lz[id << 1] = 1, lz[id << 1 | 1] = 1;
}
void bd(int l = 1, int r = N, int id = 1){
    if(l == r) {tr[id] = 10; return;}
    int m = l + r >> 1;
    bd(l, m, id << 1), bd(m + 1, r, id << 1 | 1);
    tr[id] = tr[id << 1] + tr[id << 1 | 1];
}
int sear(int po, int va, int l = 1, int r = N, int id = 1){
    pus(id, l != r);
    if(r <= po) return 0;
    if(l == r){
        int ret = min(va, tr[id]);
        tr[id] = max(0, tr[id] - va);
        return ret;
    }
    if(l > po and tr[id] <= va) {
        int ret = tr[id];
        tr[id] = 0, lz[id << 1] = 1, lz[id << 1 | 1] = 1;
        return ret;
    }
    int m = l + r >> 1;
    int ll = sear(po, va, l, m, id << 1);
    int rr = sear(po, va - ll, m + 1, r, id << 1 | 1);
    tr[id] = tr[id << 1] + tr[id << 1 | 1];
    return ll + rr;
}
int seal(int po, int va, int l = 1, int r = N, int id = 1){
    
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M; 
    --N; bd();
    for(int i = 0, t, u, v; i < M; ++i){
        cin >> t >> u;
        if(t == 1){
            cin >> v;
        } else cout << que(v, v) << '\n';
    }
}