#include <bits/stdc++.h>
using namespace std;
const int X = 3e5 + 5;
const long MD = 1e9 + 7;
int N, ar[X], mp[X], ft[X];
long an = 0, fact[X] = {1};
void ud(int po, int va){for(++po; po < X; po += -po & po) ft[po] += va;}
int gt(int po, int re = 0){for(++po; po; po -= -po & po) re += ft[po]; return re;}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> ar[i], mp[i] = ar[i];
	sort(mp, mp + N);
	for(int i = 0; i < N; ++i) ar[i] = lower_bound(mp, mp + N, ar[i]) - mp, ud(i, 1);
	for(int i = 1; i <= N; ++i) fact[i] = (fact[i - 1] * i) % MD;
	for(int i = 0; i < N; ++i){
		ud(ar[i], -1);
		(an += fact[N - i - 1] * gt(ar[i])) %= MD;
	}
	cout << (an + 1) % MD;
}