#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;
const int X = 5e5 + 5;
int N, M, K, st[X], p[X];
long long cost;
vector<iii> ed;
vector<int> br, sh;
stack<int> stk;
int fd(int u){ return p[u] = (p[u] == u)? u : fd(p[u]); }
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 1, u, v, w; i <= M; ++i) cin >> u >> v >> w, ed.emplace_back(u, v, w);
    for(int i = 1, u, v; i <= K; ++i) cin >> u >> v, ed.emplace_back(u, -1, v);
    iota(p, p + N + 1, 0);
    iota(st, st + M + K, 0);
    sort(st, st + M + K, [](const int &l, const int &r){return get<2>(ed[l]) < get<2>(ed[r]);});
    for(int i = 0; sh.size() + br.size() < N - 1; ++i){
        auto [u, v, w] = ed[st[i]];
        if(v == -1) {br.emplace_back(st[i]); cost += w; continue;}
        u = fd(u), v = fd(v);
        if(u == v) continue;
        p[u] = v;
        sh.emplace_back(st[i]); 
        cost += w;
    }
    cout << cost << '\n' << sh.size() << '\n';
    for(int i: sh) cout << i + 1 << '\n';
    cout << br.size() << '\n';
    for(int i = 1; i <= N; ++i) if(p[i] == i) stk.emplace(i);
    for(int i: br){
        cout << i - M + 1 << ' ';
        int x = stk.top(); stk.pop();
        if(x == fd(get<0>(ed[i]))) {
            cout << stk.top() << '\n'; 
            p[stk.top()] = x; 
            stk.pop(); stk.emplace(x);
        }
        else {p[x] = fd(get<0>(ed[i])); cout << x << '\n';}
    }
}