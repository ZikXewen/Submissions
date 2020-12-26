#include <bits/stdc++.h>
using namespace std;
const int X = 1e3 + 5;
int N, sm[X], v[X];
int dfs(int x){
    if(x > N) return 0;
    return sm[x] = v[x] + dfs(x << 1) + dfs(x << 1 | 1);
}
void dfs2(int x){
    if(x << 1 > N) return;
    dfs2(x << 1), dfs2(x << 1 | 1);
    cout << v[x] << ' ' << v[x << 1] + v[x << 1 | 1] << ' ' << sm[x] - v[x] << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> v[i];
    dfs(1);
    dfs2(1);
    cout << sm[1];
}