#include <bits/stdc++.h>
#define vv vector<vector<int>>
using namespace std;
const int X = 31, MD = 1e9 + 7;
int N, ann;
vv ar[X] = {{{0, 1, 1}, {2, 1, 0}, {0, 1, 2}}}, an = {{1}, {1}, {1}};
vv mu(vv u, vv v) {
	vv re(u.size(), vector<int>(v[0].size()));
	for(int i = 0; i < u.size(); i++) 
		for(int j = 0; j < v[0].size(); j++)
				for(int k = 0; k < v.size(); k++)
					re[i][j] = (re[i][j] + (1ll * u[i][k] * v[k][j]) % MD) % MD;
	return re;
}
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= log2(N); i++) ar[i] = mu(ar[i - 1], ar[i - 1]);
	for(int ct = 0; N; N >>= 1, ct++) if(N & 1) an = mu(ar[ct], an);
	printf("%d", (((1ll * an[0][0]) << 1) + an[1][0]) % MD);
}
