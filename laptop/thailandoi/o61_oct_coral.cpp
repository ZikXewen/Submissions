#include <bits/stdc++.h>
using namespace std;
int K, M, i = 0, a, b, p[1 << 21], ct;
int fd(int x){return p[x] = p[x] == x? x : fd(p[x]);}
int main(){
	scanf("%d %d", &K, &M);
	iota(p, p + ((1 << K) | 1), 0);
	while(++i){
		scanf("%d %d", &a, &b);
		a = fd(b + (1 << a)), b = fd(b);
		if(a != b) p[a] = b, ct++;
		if(ct == (1 << K)) break;
	} printf("%d", i);
}
