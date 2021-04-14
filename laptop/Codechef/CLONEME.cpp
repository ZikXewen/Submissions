#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
const long long HS = 67867967, MD = 1e9 + 7;
struct one{
    int va;
    long long ha;
    one *l, *r;
    one() = default;
} *tr[X];
int T, N, Q;
long long hsh[X] = {1ll};
void bd(one *cr, int l = 0, int r = X - 1){
    if(l == r) return;
    int m = (l + r) >> 1;
    bd(cr -> l = new one(), l, m);
    bd(cr -> r = new one(), m + 1, r);
}
void add(one *cr, one *pa, int va, int l = 0, int r = X - 1){
    if(l == r) return cr -> va = (pa -> va) + 1, cr -> ha = ((pa -> ha) + hsh[va]) % MD, void();
    int m = (l + r) >> 1;
    if(va <= m) add(cr -> l = new one(), pa -> l, va, l, m), cr -> r = pa -> r;
    else add(cr -> r = new one(), pa -> r, va, m + 1, r), cr -> l = pa -> l;
    cr -> va = (cr -> l -> va) + (cr -> r -> va);
    cr -> ha = ((cr -> l -> ha) + (cr -> r -> ha)) % MD;
}
bool chk(one *a, one *b, one *c, one *d){return ((b -> va) - (a -> va) == (d -> va) - (c -> va)) and (((b -> ha) + (c -> ha) - (a -> ha) - (d -> ha) + MD + MD) % MD == 0);}
bool que(one *a, one *b, one *c, one *d, int l = 0, int r = X - 1, int rem = 0){
    if(chk(a, b, c, d)) return true;
    if(l == r) return abs((b -> va) + (c -> va) - (a -> va) - (d -> va)) <= 1;
    bool leh = chk(a -> l, b -> l, c -> l, d -> l);
    bool rih = chk(a -> r, b -> r, c -> r, d -> r);
    bool len = ((b -> l -> va) - (a -> l -> va)) or ((d -> l -> va) - (c -> l -> va));
    bool rin = ((b -> r -> va) - (a -> r -> va)) or ((d -> r -> va) - (c -> r -> va));
    int m = (l + r) >> 1;
    auto gor = [=](int ty){return que(a -> r, b -> r, c -> r, d -> r, m + 1, r, ty);};
    auto gol = [=](int ty){return que(a -> l, b -> l, c -> l, d -> l, l, m, ty);};
    if(rem == 1) return (leh and gor(1)) or (!rin and gol(1));
    if(rem == 2) return (rih and gol(2)) or (!len and gor(2));
    if(!leh and !rih) return gol(1) and gor(2);
    if(leh) return gor(0);
    return gol(0);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    for(int i = 1; i < X; ++i) hsh[i] = (hsh[i - 1] * HS) % MD;
    while(T--){
        cin >> N >> Q;
        bd(tr[0] = new one());
        for(int i = 0, u; i < N; ++i) cin >> u, add(tr[i + 1] = new one(), tr[i], u);
        for(int i = 0, u, v, w, z; i < Q; ++i) cin >> u >> v >> w >> z, cout << (que(tr[u - 1], tr[v], tr[w - 1], tr[z])? "YES\n" : "NO\n");
    }
}