#include <bits/stdc++.h>
using namespace std;
const int X = 15005, NE = 5001;
int N; short ft[X][X];
void ud(int u, int v, int va){ for(int i = u; i < X; i += -i & i) for(int j = v; j < X; j += -j & j) ft[i][j] += va; }
int que(int u, int v, int re = 0){ for(int i = u; i; i -= -i & i) for(int j = v; j; j -= -j & j) re += ft[i][j]; return re; }
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0, u, v, l, r; i < N; ++i){
		cin >> u >> v; u += NE;
		l = u - v, r = u + v;
		cout << que(l, r) << '\n';
		ud(l, l, 1), ud(l, r + 1, -1), ud(r + 1, l, -1), ud(r + 1, r + 1, 1);
	}
}
