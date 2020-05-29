#include <bits/stdc++.h>
using namespace std;
const int X = 7005;
int N, M, x[2], y[2][X], an[2][X], stk[X];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1, u; i <= N; ++i){
        string inp; cin >> inp; x[0] = 0;
        for(int j = 1; j <= M; ++j){
            bool cx = j & 1, cy = i & 1, u = inp[j - 1] - '0';
            x[cx] = u * (x[!cx] + 1);
            y[cy][j] = u * (y[!cy][j] + 1);
            an[cy][j] = u * (min(an[!cy][j - 1], min(x[!cx], y[!cy][j])) + 1);
            ++stk[an[cy][j]];
        }
    }
    for(int i = X - 1; i; --i) stk[i - 1] += stk[i];
    for(int i = 1; i <= min(N, M); ++i) cout << stk[i] << '\n';
}