#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair<int64, int64> ii;
int N;
int64 A, B, per, ans;
vector<ii> ar;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B;
    if(A / __gcd(A, B + 1) >= LLONG_MAX / B) per = LLONG_MAX;
    else per = A / __gcd(A, B + 1) * B;
    for(int64 i = 0, u, v; i < N; ++i){
        cin >> u >> v;
        if(v - u + 1 >= per) {cout << per; return 0;}
        u %= per, v %= per;
        if(u <= v) ar.emplace_back(u, v);
        else ar.emplace_back(u, per - 1), ar.emplace_back(0, v);
    }
    sort(ar.begin(), ar.end());
    for(int64 i = 0, l = 0, r = -1;; ++i){
        if(i == ar.size()) {ans += r - l + 1; break;}
        if(ar[i].first <= r) r = max(r, ar[i].second);
        else ans += r - l + 1, l = ar[i].first, r = ar[i].second;
    }
    cout << ans;
}