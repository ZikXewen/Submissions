#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, se[X], ft[X], ar[X];
stack<int> stk;
void ud(int u, int va){for(++u; u <= N; u += -u & u) ft[u] += va;}
int gt(int u, int ret = 0){for(++u; u; u -= -u & u) ret += ft[u]; return ret;}
int fd(int va){
    int l = 0, r = N - 1;
    while(l < r){
        int m = (l + r) >> 1;
        if(gt(m) < va) l = m + 1;
        else r = m;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> ar[i];
    sort(ar, ar + N);
    for(int i = 0; i < N; ++i) cin >> se[i], ++se[i], ud(i, 1);
    for(int i = N - 1; i >= 0; --i){
        int tem = fd(se[i]);
        stk.emplace(ar[tem]), ud(tem, -1);
    }
    while(stk.size()) cout << stk.top() << '\n', stk.pop();
}