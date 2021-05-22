#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ii;
typedef int64_t i64;
const int X = 8e4 + 5, Y = 300, Z = 1e6 + 5;
int N, M, K, L, ar[X], bk[Y], f[Z];
i64 ret, ans[X];
vector<ii> qu[Y];
vector<vector<i64>> pw(Z, vector<i64>(1, 1));
int main(){
    auto add = [&](int u){
        int a = f[u = ar[u]]++;
        (ret += pw[u][a+1] - pw[u][a] + K) %= K;
    };
    auto del = [&](int u){
        int a = f[u = ar[u]]--;
        (ret += pw[u][a-1] - pw[u][a] + K) %= K;
    };
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    L = sqrt(N) + 1;
    for(int i = 0; i < N; ++i) 
        cin >> ar[i],
        pw[ar[i]].emplace_back(pw[ar[i]].back() * ar[i] % K);
    for(int i = 0; i < Z; ++i)
        for(int j = 0; j < pw[i].size(); ++j)
            (pw[i][j] *= j) %= K;
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v; --u, --v;
        if(u/L == v/L){
            for(int j = u; j <= v; ++j) add(j);
            ans[i] = ret;
            for(int j = u; j <= v; ++j) f[ar[j]] = 0; ret = 0; // RESET
        }
        else qu[u/L + 1].emplace_back(v, u, i);
    }
    for(int i = 0; i < L; ++i) sort(qu[i].begin(), qu[i].end()), qu[i].emplace_back(-1, 0, 0); 
    for(int i = 0; i < L; ++i){
        for(int j = i*L; j < N; ++j){ 
            add(j);
            while(get<0>(qu[i][bk[i]]) == j){
                auto [u, v, w] = qu[i][bk[i]];
                for(int k = i*L - 1; k >= v; --k) add(k); 
                ans[w] = ret;
                for(int k = v; k < i*L; ++k) del(k);
                ++bk[i];
            }
        }
        for(int j = i*L; j <= N; ++j) f[ar[j]] = 0; ret = 0; // RESET
    }
    for(int i = 0; i < M; ++i) cout << ans[i] << '\n';
}