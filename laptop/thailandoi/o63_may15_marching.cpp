#include <bits/stdc++.h>
using namespace std;
const int X = 1505;
int N, M, g[X][X], tl[X][X], tr[X][X], bl[X][X], br[X][X], an = INT_MAX, sm[X][X];
int dist(int ui, int uj, int vi, int vj){
    return sm[vi][vj] - sm[vi][uj - 1] - sm[ui - 1][vj] + sm[ui - 1][uj - 1];
}
void minn(int &u, int v){u = min(u, v);}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i <= N + 1; ++i) 
        fill_n(tl[i], M + 2, INT_MAX),
        fill_n(tr[i], M + 2, INT_MAX),
        fill_n(bl[i], M + 2, INT_MAX),
        fill_n(br[i], M + 2, INT_MAX);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) cin >> g[i][j];
    tl[1][1] = g[1][1];
    tr[1][M] = g[1][M];
    bl[N][1] = g[N][1];
    br[N][M] = g[N][M];
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j)
        sm[i][j] += g[i][j] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1]; 
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j)
        minn(tl[i + 1][j], tl[i][j] + g[i + 1][j]), minn(tl[i][j + 1], tl[i][j] + g[i][j + 1]);
    for(int i = 1; i <= N; ++i) for(int j = M; j; --j)
        minn(tr[i + 1][j], tr[i][j] + g[i + 1][j]), minn(tr[i][j - 1], tr[i][j] + g[i][j - 1]);
    for(int i = N; i; --i) for(int j = 1; j <= M; ++j)
        minn(bl[i - 1][j], bl[i][j] + g[i - 1][j]), minn(bl[i][j + 1], bl[i][j] + g[i][j + 1]);
    for(int i = N; i; --i) for(int j = M; j; --j)
        minn(br[i - 1][j], br[i][j] + g[i - 1][j]), minn(br[i][j - 1], br[i][j] + g[i][j - 1]);
    for(int i = 1; i <= N; ++i){
        int fromleft = INT_MAX;
        for(int j = 1; j <= M; ++j){
            minn(fromleft, tl[i][j] + bl[i][j] + dist(i, j, i, M) - 2 * g[i][j]);
            minn(an, tr[i][j] + br[i][j] - dist(i, j, i, M) - g[i][j] + fromleft);
        }
    }
    for(int j = 1; j <= M; ++j){
        int fromtop = INT_MAX;
        for(int i = 1; i <= N; ++i){
            minn(fromtop, tl[i][j] + tr[i][j] + dist(i, j, N, j) - 2 * g[i][j]);
            minn(an, bl[i][j] + br[i][j] - dist(i, j, N, j) - g[i][j] + fromtop);
        }
    }
    cout << an;
}