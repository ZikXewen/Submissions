#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tuple<int, int, int> ii;
const int X = 2e5 + 5;
struct one{
    int st[X << 2], lz[X << 2];
    void ps(int id, bool nx){
        if(!lz[id]) return;
        if(nx) lz[id << 1] += lz[id], lz[id << 1 | 1] += lz[id];
        st[id] += lz[id]; lz[id] = 0;
    }
    void ud(int l, int r, int va, int ll = 1, int rr = X, int id = 1){ 
        ps(id, ll != rr);
        if(ll > r or rr < l or l > r) return;
        if(ll >= l and rr <= r) return lz[id] += va, ps(id, ll != rr);
        int m = (ll + rr) >> 1;
        ud(l, r, va, ll, m, id << 1), ud(l, r, va, m + 1, rr, id << 1 | 1);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    int qu(int l, int r, int ll = 1, int rr = X, int id = 1){
        ps(id, ll != rr);
        if(ll > r or rr < l or l > r) return 0;
        if(ll >= l and rr <= r) return st[id];
        int m = (ll + rr) >> 1;
        return max(qu(l, r, ll, m, id << 1), qu(l, r, m + 1, rr, id << 1 | 1));
    }
} dp[3];
int N;
vector<ii> ar;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 0, u, v, w; i < N; ++i) 
        cin >> u >> v >> w, ar.emplace_back(u, INT_MAX, 0), ar.emplace_back(v + 1, u, w), st.insert(u), st.insert(v + 1);
    sort(ar.begin(), ar.end());
    for(auto [u, v, w]: ar){
        u = st.order_of_key(u) + 1; v = st.order_of_key(v) + 1;
        if(w) for(int i = 0; i < 3; ++i) dp[i].ud(v, u - 1, w);
        else for(int i = 1; i < 3; ++i) dp[i].ud(u, u, max(dp[i].qu(u, u), dp[i - 1].qu(1, u - 1)) - dp[i].qu(u, u)); // can op more
    }
    cout << dp[2].qu(1, X);
}
/*
6
0 10 10
7 15 10 
20 30 20
25 40 20
35 45 5
60 80 300
*/