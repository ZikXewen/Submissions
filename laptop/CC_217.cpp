#include <bits/stdc++.h>
#define long long long
using namespace std;
const int INF = 2e9, X = 1e5 + 5;
int N, M, K, a1[X], a2[X], a, b, c, d, k;
int ck(int u){
	int o = upper_bound(a1 + a, a1 + c + 1, u + a1[a - 1]) - (a1 + a);
	int p = upper_bound(a2 + b, a2 + d + 1, u + a2[b - 1]) - (a2 + b);
	return o + p;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i <= N; ++i) cin >> a1[i], a1[i] += a1[i - 1];
	for(int i = 1; i <= M; ++i) cin >> a2[i], a2[i] += a2[i - 1];
	for(int i = 0; i < K; ++i){
		cin >> a >> b >> c >> d >> k; long m, mn, mx;
		for(mx = INF, mn = 0; mn < mx;){
			m = (mn + mx) >> 1; //cout << ck(m) << ' ' << mn << ' ' << mx << '\n';
			if(ck(m) < k) mn = m + 1;
			else mx = m;
		}
		cout << mn << '\n';
	}
}
