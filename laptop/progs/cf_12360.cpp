#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	scanf("%d", &T);
	while(T--) {
		int u, v, w, ct;
		scanf("%d %d %d", &u, &v, &w);
		if((w >> 1) > v) v -= ct = v;
		else v -= ct = (w >> 1);
		if((v >> 1) <= u) ct += (v >> 1);
		else ct += u;
		printf("%d\n", ct * 3);
	}
}
