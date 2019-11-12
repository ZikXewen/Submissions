#include<cstdio>
#include<cstring>
#include<algorithm>
#define MX 1005
using namespace std;
int mm[MX][MX],N; char v[MX];
int dp(int s,int e){
	if(mm[s][e]!=-1) return mm[s][e];
	if(s>=e) return mm[s][e]=0;
	if(v[s]==v[e]) return mm[s][e]=dp(s+1,e-1)+1; 
	int ret=0;
	for(int i=s;i<e;i++) ret=max(ret,dp(s,i)+dp(i+1,e));
	return mm[s][e]=ret;
}
int main(){
	memset(mm,-1,sizeof mm);
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf(" %c",&v[i]);
	printf("%d",dp(0,N-1));
}
