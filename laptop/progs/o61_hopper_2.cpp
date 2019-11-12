#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MXN 3005
using namespace std;
int N,M,v[MXN],mx,mm[MXN];
vector<int> ed[MXN];
void pre(){
	for(int i=0;i<N;i++) {mx=MXN; for(int j=1;j<N;j++) if(v[(i+j)%N]>v[i]&&mx>=v[(i+j)%N]) mx=v[(i+j)%N],ed[i].emplace_back(j);}
}
int dp(int x,int val){ 
	if(mm[x]!=-1) return mm[x];
	if(ed[x].empty()) return mm[x]=0;
	auto it=upper_bound(ed[x].begin(), ed[x].end(),val);
	for(auto i=it-1;i>=ed[x].begin();i--) mm[x]=max(mm[x],dp((*i+x)%N,val)+1);
	return max(mm[x],0);
}
int bsearch(int s,int e){
	if(s>e) return s;
	memset(mm,-1,sizeof mm);
	int m=(s+e)>>1;
	for(int i=0;i<N;i++) if(mm[i]==-1&&dp(i,m)>=M) return bsearch(s,m-1);
	return bsearch(m+1,e);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	pre();
	printf("%d",bsearch(1,N));
}
