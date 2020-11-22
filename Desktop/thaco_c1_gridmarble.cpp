#include <bits/stdc++.h>
using namespace std;
class one{
    public:
    long long x, y;
    int r, id;
    one(int _x, int _y, int _r, int _id): x(_x), y(_y), r(_r), id(_id) {}
    bool operator<(const one &R){return r < R.r;}
};
int N, M, ct, p[30300], sm[30300], an = 2e9;
vector<one> yak, wall;
set<int> st;
vector<int> g[30300];
bool vs[30300];
void fl(int u, int ds = 0){
    sm[u] += ds; vs[u] = 1;
    for(int i: g[u]) if(!vs[i]) fl(i, ds + 1);
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v; i < N; ++i) cin >> u >> v, yak.emplace_back(u, v, 0, ++ct);
    for(int i = 0, u, v, w; i < M; ++i) cin >> u >> v >> w, wall.emplace_back(u, v, w, ++ct);
    sort(wall.begin(), wall.end());
    for(auto [xu, yu, _a, iu]: yak){
        st.emplace(iu);
        for(auto [xv, yv, r, iv]: wall) 
            if((xv - xu) * (xv - xu) + (yv - yu) * (yv - yu) < r * r) 
                p[iu] = iv, st.emplace(iu = iv);
    }
    for(int i: st) if(p[i]) g[i].emplace_back(p[i]), g[p[i]].emplace_back(i);
    for(auto x: yak) memset(vs, 0, sizeof vs), fl(x.id);
    for(int i: st) an = min(an, sm[i]);
    cout << an;
}