#include <bits/stdc++.h>
#define ii tuple<int, int, int, int>
using namespace std;
const int X = 1e4 + 5;
int ct[X], p[X], mul[3] = {4, 8, 16};
long long va[X], ls;
string in;
priority_queue<ii> q;
int fd(int x) {return (p[x] < 0)? x : p[x] = fd(p[x]);}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> in;
    memset(p, -1, sizeof p);
    fill_n(va, in.length(), 20);
    for(int i = 0, u = -1, ct = 0, sym, lvlsym; i < in.length(); ++i){
        if(in[i] == '[') ++ct;
        else if(in[i] == ']') --ct;
        else if(in[i] >= '1' and in[i] <= '3') sym = in[i] - '1', lvlsym = ct;
        else{
            if(u != -1) q.emplace(lvlsym, sym, -u, i);
            u = i;
        }
    }
    while(q.size()){
        auto [w, z, u, v] = q.top(); q.pop();
        u = -u; u = fd(u), v = fd(v);
        p[u] = v; ls = va[v] = (va[u] + va[v]) + ((va[u] + va[v]) * mul[z] / 100);
    }
    cout << ls;
}