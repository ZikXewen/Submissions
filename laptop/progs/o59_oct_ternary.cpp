#include <bits/stdc++.h>
using namespace std;
const int X = 105, MD = 1e9 + 7;
int N, pr[X], in[X], po[X], mm[X][X][X];
int dp(int u = 0, int v = 0, int le = N){
	int &cr = mm[u][v][le]; if(cr != -1) return cr;
	if(le == 0) return cr = 1;
	if(le == 1) return cr = (pr[u] == in[v]);
	int sz = po[pr[u]] - v, re = 0;
	if(sz > le || sz < 0) return cr = 0;
	for(int i = 0; i < le - sz; ++i) re = (re + (1ll * dp(u + sz + 1, v + sz + 1, i) * dp(u + sz + i + 1, v + sz + i + 1, le - sz - i - 1)) % MD) % MD;
	return cr = (1ll * re * dp(u + 1, v, sz)) % MD;

}int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) scanf("%d", pr + i);
	for(int i = 0; i < N; ++i) scanf("%d", in + i), po[in[i]] = i;
	memset(mm, -1, sizeof mm);
	printf("%d\n", dp());
}
