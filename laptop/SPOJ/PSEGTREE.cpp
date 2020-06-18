#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
struct node{
    int va;
    node *l, *r;
    node() = default;
} *hd[X];
int N, Q, ar[X], ct;
void bd(node *cur, int ll = 1, int rr = N){
    if(ll == rr) return void(cur -> va = ar[ll]);
    int m = (ll + rr) >> 1;
    bd(cur -> l = new node(), ll, m);
    bd(cur -> r = new node(), m + 1, rr);
    cur -> va = cur -> l -> va + cur -> r -> va;
}
void ud(int po, int va, node *prv, node *cur, int ll = 1, int rr = N){
    if(ll == rr) return void(cur -> va = prv -> va + va);
    int m = (ll + rr) >> 1;
    if(po <= m) ud(po, va, prv -> l, cur -> l = new node(), ll, m), cur -> r = prv -> r;
    else ud(po, va, prv -> r, cur -> r = new node(), m + 1, rr), cur -> l = prv -> l;
    cur -> va = cur -> l -> va + cur -> r -> va;
}
int gt(node *cur, int l, int r, int ll = 1, int rr = N){
    if(r < ll or l > rr) return 0;
    if(l <= ll and r >= rr) return cur -> va;
    int m = (ll + rr) >> 1;
    return gt(cur -> l, l, r, ll, m) + gt(cur -> r, l, r, m + 1, rr);
}
int main(){ 
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> ar[i];
    cin >> Q;
    bd(hd[0] = new node());
    for(int i = 0, u, v, w, z; i < Q; ++i){
        cin >> u >> v >> w >> z;
        if(u == 1){
            ud(w, z, hd[v], hd[++ct] = new node());
        } else {
            cout << gt(hd[v], w, z) << '\n';
        }
    }
}