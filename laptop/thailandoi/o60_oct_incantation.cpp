#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int X = 150;
int N, K, cr;
lint ar[2][X][X], an[X], te[X];
int main(){
	scanf("%d %d", &N, &K); N -= K - 1;
	int all = 1 << K;
	for(int i = 0; i < all; i++) fill_n(ar[0][i], all, -1e18), fill_n(ar[1][i], all, -1e18);
	for(int i = 0, u; i < all; i++) scanf("%d", &u), 
		ar[0][i >> 1][i] = ar[0][(1 << (K - 1)) | (i >> 1)][i] = u;
	do{
		if(N & 1){
			memset(te, 0, sizeof te);
			for(int i = 0; i < all; i++) for(int j = 0; j < all; j++) 
				te[j] = max(te[j], an[i] + ar[cr][i][j]);
			copy(te, te + all, an);
		}
		cr ^= 1;
		memset(ar[cr], 0, sizeof(ar[cr]));
		for(int k = 0; k < all; k++) for(int i = 0; i < all; i++) for(int j = 0; j < all; j++) 
			ar[cr][i][j] = max(ar[cr][i][j], ar[cr ^ 1][i][k] + ar[cr ^ 1][k][j]);
	} while(N >>= 1);
	printf("%lld", *max_element(an, an + all));
}
/*
5 2 1 5 4 1
*/
