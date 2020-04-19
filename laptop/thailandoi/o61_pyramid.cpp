#include <bits/stdc++.h>
using namespace std;
const int X = 10005, NE = 5001;
int N, ft[X][X];
void ud(int x, int y){ for(int i = x; i < X; i += -i & i) for(int j = y; j < X; j += -j & j) ++ft[i][j]; }
int gt(int x, int y, int ret = 0){ for(int i = x; i; i -= -i & i) for(int j = y; j; j -= -j & j) ret += ft[i][j]; return ret; }
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0, u, v, l, r; i < N; ++i) {
		cin >> u >> v;
		l = u - v + NE, r = u + v;
		cout << gt(l, X - 1) - gt(l, r - 1) << '\n'; ud(l, r);
	}
}
