#include <bits/stdc++.h>
using namespace std;
bitset<int (1e6 + 5)> x;
int N;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 0, u; i < N; ++i){
        cin >> u;
        if(x[u]) continue;
        cout << u << '\n';
        x[u] = 1;
    }
}