#include <bits/stdc++.h>
using namespace std;
const int X = 355, INF = 2e9;
int N, K, ar[X], ct[X], an;
struct line{
    int m, c, w;
    line() = default;
    line(int _m, int _c, int _w) : m(_m), c(_c), w(_w) {}
    int operator()(int x){return w == -1? INF : m * (x + c) + (ct[w] + 1) * ct[w ^ 1];}
};
vector<line> tr;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> ar[i];
    sort(ar, ar + N, greater<int>());
    for(int i = 0; i < N; ++i){
        if(i < (K << 1)) tr.emplace_back(1, ar[i], i);
        else{
            vector<line> tm;
            line mn = line(0, 0, -1);
            for(auto j: tr) ct[j.w] = j.m;
            for(auto j: tr) if(j(ar[i]) < mn(ar[i])) mn = j;
            for(auto j: tr) 
                if(j.w == mn.w) tm.emplace_back(j.m + 1, j.c + ar[i], j.w);
                else tm.emplace_back(j);
            tr = tm;
        }
    }
    for(auto i: tr) ct[i.w] = i.m;
    for(auto i: tr) an += (i.m - 1) * i.c + ct[i.w] * ct[i.w ^ 1];
    cout << an;
}