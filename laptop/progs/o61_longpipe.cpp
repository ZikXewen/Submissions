#include <cstdio>
#include <algorithm>
#include <array>
#define MXN 1000000
using namespace std;
int N,sm;
array<array<int,5>,5 > sta={1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0},ed={1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0},ret;
array<array<array<int,5>,5 >,MXN > st;
array<array<int,5>,5 > bd(int s,int e){ printf("%d %d\n",s,e);
	if(e==1) return sta; if(s==N) return ed;
	if(st[e-s][0][0]) return st[e-s];
	int m=(s+e)>>1;
	array<array<int,5>,5 > L=bd(s,m),R=bd(m+1,e),cur{};
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++) cur[i][j]+=L[i][k]*R[k][j];
	return st[e-s]=cur;
}
int main(){
	scanf("%d",&N); if(N==1) {printf("7"); return 0;}
	st[0]={1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,1};
	ret=bd(1,N);
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) sm+=ret[i][j];
	printf("%d",sm);
}
