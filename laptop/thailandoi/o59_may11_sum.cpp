#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 1e5 + 5;
const long INF = 1e11 + 5;
int N, tr[X];
long K, ar[X];
vector<long> co;
int _id(long u){
    int ret = upper_bound(co.begin(), co.end(), u) - co.begin(); //care
    return ret;
}
void ud(long id){for(id = _id(id); id < X; id += -id & id) ++tr[id];}
int gt(long id){int ret = 0; for(id = _id(id); id; id -= -id & id) ret += tr[id]; return ret;}
long ck(long in){
    long ret = 0;
    memset(tr, 0, sizeof tr);
    for(int i = 1; i <= N; ++i) ud(ar[i - 1]), ret += gt(ar[i] - in);
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) cin >> ar[i], co.emplace_back(ar[i] += ar[i - 1]);
    co.emplace_back(0); sort(co.begin(), co.end());
    co.resize(unique(co.begin(), co.end()) - co.begin());
    long l = -INF, r = INF;
    while(l < r){
        long m = (l + r + 1) >> 1;
        if(ck(m) >= K) l = m;
        else r = m - 1;
    }
    cout << l;
}