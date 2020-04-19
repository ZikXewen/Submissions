#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 3e5 + 5;
int N, sz, nw[X], ft[2][X]; long in[X], mp[X], an;
void ud(bool ty, int po, bool va){for(po += 2; po < X; po += -po & po) ft[ty][po] += (va? 1 : -1);}
int gt(bool ty, int po, int re = 0){for(po += 2; po; po -= -po & po) re += ft[ty][po]; return re;}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> in[i], mp[i] = in[i];
	sort(mp, mp + N); sz = unique(mp, mp + N) - mp;
	for(int i = 0; i < N; ++i) nw[i] = lower_bound(mp, mp + sz, in[i]) - mp;
	for(int i = 0; i < N; ++i) ud(1, nw[i], 1);
	for(int i = 0; i < N; ++i) ud(1, nw[i], 0), an += 1ll * gt(0, nw[i] - 1) * gt(1, nw[i] - 1), ud(0, nw[i], 1);
	cout << an;
}