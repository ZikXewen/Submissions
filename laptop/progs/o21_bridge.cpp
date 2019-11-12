#include <cstdio>
#include <algorithm>
#define MXN 3005
using namespace std;
int N,v[2][MXN],mm[2][MXN];
int main(){
	scanf("%d",&N);
	for(int j=0;j<2;j++) for(int i=0;i<N;i++) scanf("%d",&v[j][i]);
	for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) 
		if(v[0][i]==v[1][j]) mm[(i&1)^1][j+1]=max(mm[(i&1)^1][j+1],mm[i&1][j]+1); 
		else mm[(i&1)^1][j]=max(mm[(i&1)^1][j],mm[i&1][j]), mm[i&1][j+1]=max(mm[i&1][j+1],mm[i&1][j]);
	printf("%d",mm[N&1][N]);
}
