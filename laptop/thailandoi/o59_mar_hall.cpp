#include <bits/stdc++.h>
using namespace std;
const int X = 2e4 + 5;
int N, mx = -1; char c;
vector<string> ar;
int main(){
    cin >> N; ar.resize(N);
    for(int i = 0; i < N; ++i) cin >> c, ar[0].push_back(c);
    for(int i = 1; i < N; ++i) for(int j = 0; j < N; ++j) ar[i].push_back(ar[0][(i + j) % N]);
    sort(ar.begin(), ar.end());
    for(int i = 1; i < N; ++i) for(int j = 0; j < N; ++j) if(ar[i - 1][j] != ar[i][j]) {mx = max(mx, j); break;}
    cout << mx;
}