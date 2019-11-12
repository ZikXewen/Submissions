#include <bits/stdc++.h>
using namespace std;
int N, ct, ar[305][305];
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		if(i & 1) ar[i][N - j - 1] = ++ct;
		else ar[i][j] = ++ct;
	for(int i = 0; i < N; i++) {for(int j = 0; j < N; j++) printf("%d ",ar[j][i]); printf("\n");}
}
