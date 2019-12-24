#include <bits/stdc++.h>
using namespace std;
const int X = 305;
int M, N, ar[X][X], te[X][X], bx[X][X][X], nf[X][X][X], an, arr[X][X];
void box(){
	for(int i = 1; i <= M; i++) {
		for(int j = i; j <= M; j++){
			for(int k = 1, ls = 0; k <= N; k++){
				bx[i][j][k] = (ls += te[j][k] - te[i - 1][k]);
				if(ls < 0) ls = 0;
			}
		}
	}
	for(int i = 0; i <= M + 1; i++) {
		for(int j = 0; j <= M; j++){
			for(int k = 0; k <= N; k++){
				nf[i][j][k] = -1e9;
			}
		}
	}
	for(int k = 1; k <= N; k++){
		for(int i = M; i; i--) {
			for(int j = i; j <= M; j++){
				nf[i][j][k] = max({nf[i][j - 1][k], nf[i + 1][j][k], nf[i][j][k - 1], bx[i][j][k]});
			}
		}
	}
	for(int i = 1; i <= M; i++) {
		for(int j = i; j <= M; j++){
			for(int k = N, ls = 0; k > 1; k--){
				ls += te[j][k] - te[i - 1][k];
				an = max(an, ls + nf[i][j][k - 2]);
				if(ls < 0) ls = 0;
			}
		}
	}
}
int main(){
	scanf("%d %d", &M, &N);
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) scanf("%d", &ar[i][j]), arr[j][i] = ar[i][j];
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) te[i][j] = te[i - 1][j] + ar[i][j];
	box();
	
	memset(te, 0, sizeof te); memset(bx, 0, sizeof bx); memset(nf, 0, sizeof nf);
	for(int i = 1; i <= M; i++) reverse(ar[i] + 1, ar[i] + N + 1);
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) te[i][j] = te[i - 1][j] + ar[i][j];
	box();
	
	swap(N, M);
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) ar[i][j] = arr[i][j];
	
	memset(te, 0, sizeof te); memset(bx, 0, sizeof bx); memset(nf, 0, sizeof nf);
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) te[i][j] = te[i - 1][j] + ar[i][j];
	box();

	memset(te, 0, sizeof te); memset(bx, 0, sizeof bx); memset(nf, 0, sizeof nf);
	for(int i = 1; i <= M; i++) reverse(ar[i] + 1, ar[i] + N + 1);
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) te[i][j] = te[i - 1][j] + ar[i][j];
	box();

	printf("%d", an);
}
/*
6 6
-1000 -1000 -1000 -1000 -1000 0
-1000 1 1 1 -1000 -1000
-1000 1 1 1 -1000 -1000
-1000 -1000 -1000 -1000 -1000 -1000
-1000 -1000 -1000 -1000 -1000 -1000
-1000 1 1 1 -1000 -1000

6 6
-1000 -1000 -1000 -1000 -1000 0
-1000 -1000 -1000 -1000 -1000 -1000
1 1 -1000 -1000 1 -1000
1 1 -1000 -1000 1 -1000
1 1 -1000 -1000 -1000 -1000
-1000 -1000 -1000 -1000 -1000 -1000
*/
