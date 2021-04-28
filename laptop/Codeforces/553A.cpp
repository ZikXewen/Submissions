#include <bits/stdc++.h>
using namespace std;
const int MD = 1e9 + 7, X = 1005;
int N, u, sm;
long long cr = 1, f[X] = {1};
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i = 1; i < X; ++i) f[i] = (f[i - 1] * i) % MD;
	auto inv = [](long long u, long long ret = 1){
		for(int i = 0; i <= log2(MD); ++i, u = (u * u) % MD) 
			if((1 << i) & (MD - 2)) ret = (ret * u) % MD;
		return ret;
	};
	cin >> N; while(N--){
		cin >> u;
		cr = (cr * ((f[sm + u - 1] * inv((f[sm] * f[u - 1]) % MD)) % MD)) % MD;
		sm += u;
	}
	cout << cr << '\n';
}