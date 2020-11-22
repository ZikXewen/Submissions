#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, p[X];
long long ct[X], an[X];
bool vs[X];
int fd(int u, int hd){
    vs[u] = 1; 
    return vs[p[u]]? 1 : fd(p[u], hd) + 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) cin >> p[i];
    for(int i = 1; i <= N; ++i) if(!vs[i]) ++ct[fd(i, i)];
    for(int i = 1; i <= N; ++i) ct[i] += ct[i - 1];
    for(int i = 1; i <= N; ++i) an[i - 1] = (N / i) * ct[N];
    for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; j += i) an[i - 1] -= ct[j];
    reverse(an, an + N);
    for(int i = 0, u; i < M; ++i) cin >> u, cout << N - (upper_bound(an, an + N, u) - an) + 1 << '\n';
}