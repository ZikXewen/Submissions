#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define MXN 50005
#define ii pair<int,int>
#define iii pair<ii,int>
using namespace std;
int N,M,K,a,b,c;
bool vst[MXN];
vector<iii> v[MXN];
bool dst(int k){
	memset(vst,0,sizeof vst);
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.emplace(0,1); 
	while(!q.empty()){
		ii x=q.top(); q.pop(); //printf("%d\n",x.second);
		if(vst[x.second]) continue;
		if(x.first>K) return false;
		if(x.second==N) return true;
		vst[x.second]=true;	
		for(iii i:v[x.second])  if(!vst[i.first.first]&&i.second<=k) q.emplace(x.first+i.first.second,i.first.first);
	}
	return false;
}
int bsearch(int s,int e){
	if(s>e) return s;
	int m=(s+e)>>1;
	if(dst(m)) return bsearch(s,m-1);
	return bsearch(m+1,e);
}
int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({{b,c},i});
		v[b].push_back({{a,c},i});
	}
	int pnt=bsearch(1,M);
	if(pnt<=M) printf("%d",pnt);
	else printf("-1");
}
