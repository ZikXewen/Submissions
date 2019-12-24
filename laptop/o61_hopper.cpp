#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MXN 3005
using namespace std;
int N,M,v[MXN],mx,mm[MXN],ed[MXN][MXN],ct[MXN];
void pre(){
	for(int i=0;i<N;i++) {
		mx=MXN;
		for(int j=1;j<N;j++) if(v[(i+j)%N]>v[i]&&mx>v[(i+j)%N]){
			mx=v[(i+j)%N];
			ed[i][ct[i]++]=j;
		}
	}
}
int dp(int x,int val){  
	if(mm[x]) return mm[x];
	if(ct[x]==0) return 0;
	auto it=upper_bound(ed[x], ed[x]+ct[x],val)-1; printf("%d",*it);
	return mm[x]=dp((x+(*it))%N,val)+1;
}
int bsearch(int s,int e){
	if(s>e) return s;
	memset(mm,0,sizeof mm);
	int m=(s+e)>>1;
	for(int i=0;i<N;i++) if(!mm[i]&&dp(i,m)>=M) return bsearch(s,m-1);
	return bsearch(m+1,e);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	pre();
	//for(int i=0;i<N;i++) printf("%d ",ed[i][0]);
	printf("%d",bsearch(1,N));
}
