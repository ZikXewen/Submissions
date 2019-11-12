#include <bits/stdc++.h>
using namespace std;
const int X = 1005;
int N, K, d[X][X];
int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < K; i++) for(int j = 0; j < K; j++) scanf("%d", d[i] + j);
	for(int i = 0; i < K; i++) for(int j = 0; j < i; j++) if(d[i][j] != abs(d[0][j] - d[0][i]) && d[i][j] != N - abs(d[0][j] - d[0][i])) {d[0][i] = -d[0][i]; break;}
	for(int i = 0; i < K; i++) printf("%d\n", (d[0][i] >= 0)? d[0][i] : N + d[0][i]);
}
