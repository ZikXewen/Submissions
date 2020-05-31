#include<bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, K, ar[X], ml[X], mr[X];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) cin >> ar[i];
    int l = 0, r = 1e9; ar[N] = 1e9 + 10;
    while(l < r){
        int m = (l + r) >> 1;
        memset(ml, 0, sizeof ml);
        memset(mr, 0, sizeof mr);
        for(int ll = 0, rr = 0, ct = 0; ll < N; ++ll){
            if(rr < ll) {ml[ll] = 1e9; continue;}
            if(ll == rr) {
                ++ct;
                for(int sm = 0; sm + ar[rr] <= m and rr - ll < M;) sm += ar[rr++];
            }
            ml[ll] = ct;
        }
        for(int ll = N - 1, rr = N - 1, ct = 0; ll >= 0; --ll){
            if(ll < rr) {mr[ll] = 1e9; continue;}
            if(ll == rr) {
                ++ct;
                for(int sm = 0; sm + ar[rr] <= m and ll - rr < M and rr >= 0;) sm += ar[rr--];
            }
            mr[ll] = ct;    
        }
        bool an = 0;
        for(int i = 0; i + M < N; ++i) if(ml[i] + mr[i + M + 1] < K) {an = 1; break;}
        if(an) r = m; else l = m + 1;
    }
    cout << l;
}