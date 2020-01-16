#include <bits/stdc++.h>
using namespace std;
const int X = 35, MD = 1e9 + 7;
long long N, M, ar = 1, cr = 2;
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i <= log2(M); i++) {
		if((1 << i) & M) ar = (ar * cr) % MD;
		cr = (cr * cr) % MD;
	}
	cr = ar - 1; ar = 1;
	for(int i = 0; i <= log2(N); i++) {
		if((1 << i) & N) ar = (ar * cr) % MD;
		cr = (cr * cr) % MD;
	}
	printf("%lld", ar);
}
