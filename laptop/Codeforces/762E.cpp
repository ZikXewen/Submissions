#include <bits/stdc++.h>
#define ii tuple<int, int, int>
using namespace std;
const int X = 1e4 + 5, IN = 1e9 + 5;
struct one{
    int va;
    one *l, *r;
    one() = default;
} *tr[X];
int N, K;
long long ans;
vector<ii> ar;
void ud(one *cr, int po, int l = 1, int r = IN){
    if(l == r) return ++(cr -> va), void();
    int m = (l + r) >> 1;
    if(po <= m) ud(cr -> l? cr -> l : (cr -> l = new one()), po, l, m);
    else ud(cr -> r? cr -> r : (cr -> r = new one()), po, m + 1, r);
    ++(cr -> va);
}
int que(one *cr, int ll, int rr, int l = 1, int r = IN){
    if(ll > r or rr < l or !cr) return 0;
    if(ll <= l and  rr >= r) return cr -> va;
    int m = (l + r) >> 1;
    return que(cr -> l, ll, rr, l, m) + que(cr -> r, ll, rr, m + 1, r);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i = 0, u, v, w; i < N; ++i)
        cin >> u >> v >> w,
        ar.emplace_back(u, v, w);
    sort(ar.begin(), ar.end(), [](ii u, ii v){return get<1>(u) > get<1>(v);});
    for(auto [u, v, w]: ar){
        for(int i = max(1, w - K); i <= min(X - 1, w + K); ++i)
            ans += que(tr[i], u - v, u + v);
        ud(tr[w]? tr[w] : tr[w] = new one(), u);
    }
    cout << ans;
}