#include <bits/stdc++.h>
using namespace std;
const int X = 2005;
int N, M, ti[X], ve[X];
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d %d", &ti[i], &ve[i]);
	while(M--){
		int u, v, w, ct = 0;
		scanf("%d %d %d", &w, &u, &v);
		for(int i = 0; i < N; i++) if(1ll * (u - ti[i]) * ve[i] <= w && 1ll * (v - ti[i]) * ve[i] >= w) ct++;
		printf("%d\n", ct);
	}
}
