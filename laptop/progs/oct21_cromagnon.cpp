#include <cstdio>
using namespace std;
const int MXK=25,MXN=105,MOD=2009;
int N,K,A[MXK][MXK],v[MXN],mm[MXN][MXN][MXK],I;
int main(){
	scanf("%d",&K); for(int i=0;i<K;i++) for(int j=0;j<K;j++) scanf("%d",&A[i][j]);
	scanf("%d",&N); for(int i=0;i<N;i++) scanf("%d",&I), mm[i][i][I]++;
	for(int i=N-2;i>=0;i--) for(int j=i+1;j<N;j++) for(int k=i;k<j;k++) for(int x=0;x<K;x++) for(int y=0;y<K;y++) mm[i][j][A[x][y]] = (mm[i][j][A[x][y]] + (mm[i][k][x]*mm[k+1][j][y]))%MOD;
	for(int i=0;i<K;i++) printf("%d\n",mm[0][N-1][i]);
}
