#include <bits/stdc++.h>
using namespace std;
const int X = 1e7 + 5;
int Z, K, N, ds[X], dis[X], ax, an, mk[X];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> Z >> K >> N;
	for(int i = 1; i <= K; ++i) ds[i] = ds[i - 1] + ((__gcd(i, K) != 1)? 1 : -1);
	for(int i = 0, u, v; i < N; ++i) {
		u = v; cin >> v;
		mk[i] = ((__gcd(v, K) != 1)? 1 : -1);
		if(i) dis[i] = ds[v % K] - ds[u % K] + ds[K] * (v / K - u / K);
	}
	for(int i = 1, mn = mk[0], mx = mk[0]; i < N; ++i) {
		an = min(an, mn += dis[i]); mn = min(mn, mk[i]); 
		ax = max(ax, mx += dis[i]); mx = max(mx, mk[i]);
	}
	cout << max(-an, ax);
}