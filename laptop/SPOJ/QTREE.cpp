#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e5 + 5;
int T, N;
vector<ii> g[X];
int main(){
    cin >> T; while(T--){
        for(int i = 0; i < X; ++i) g[i].clear();
        cin >> N;
        for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        while(1){
            string str; int u, v;
            cin >> str; if(str[0] == 'D') break;
            cin >> u >> v;
        }
    }
}