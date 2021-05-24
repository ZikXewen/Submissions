#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> oset;
const int X = 2e5 + 5;
vector<ii> g[X];
int N, M, st = 1;
int64_t ans;
oset cur, all;
void dfs(int u, int p, int va){
    ans += cur.size() - cur.order_of_key(ii(va - M, 0));
    ans += all.order_of_key(ii(M - va + 1, 0));
    cur.insert(ii(va, u));
    for(auto [v, w]: g[u]) if(v != p) dfs(v, u, va+w);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1, u, v, w; i < N; ++i) 
        cin >> u >> v >> w,
        g[u].emplace_back(v, w),
        g[v].emplace_back(u, w);
    for(int i = 1; i <= N; ++i) if(g[i].size() > 2) {st = i; break;}
    all.insert(ii(0, st));
    for(auto [sc, w]: g[st]){
        dfs(sc, st, w);
        for(auto i: cur) all.insert(i);
        cur.clear();
    }
    cout << ans;
}