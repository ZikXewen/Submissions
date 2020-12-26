#include <bits/stdc++.h>
using namespace std;
int N, tab[10], win[2];
bool cur;
bool check(){
    for(int i = 1; i <= 3; ++i) if(tab[i] == tab[i + 3] and tab[i] == tab[i + 6]) return 1;
    for(int i = 1; i <= 3; ++i) if(tab[3 * i] == tab[3 * i - 1] and tab[3 * i] == tab[3 * i - 2]) return 1;
    if(tab[1] == tab[5] and tab[1] == tab[9]) return 1;
    if(tab[3] == tab[5] and tab[3] == tab[7]) return 1;
    return 0;
}
void clear(){
    for(int i = 0; i < 10; ++i) tab[i] = -i;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    clear();
    for(int i = 0, u; i < N; ++i){
        cin >> u;
        if(tab[u] >= 0) cur = 0, clear();
        tab[u] = cur;
        if(check()) clear(), ++win[cur], cur = 0;
        else cur = !cur;
    }
    cout << win[0] << '\n' << win[1];
}