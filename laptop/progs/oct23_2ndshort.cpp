#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define ii pair<int,int>
#define MXV 10005
using namespace std;
int V,E,s,t,u,v,w,d1[MXV],d2[MXV],mn=2e9;
vector<ii> ed[MXV],rev[MXV];
vector<iii> ev;
void dijk(vector<ii> in[],int out[],int st){
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.emplace(0,st);
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(out[x.second]!=-1) continue;
		out[x.second]=x.first;
		for(ii i:in[x.second]) if(out[i.first]==-1) q.emplace(x.first+i.second,i.first);
	}
}
int main(){
	memset(d1,-1,sizeof d1);
	memset(d2,-1,sizeof d2);
	scanf("%d%d%d%d",&V,&E,&s,&t);
	for(int i=0;i<E;i++){
		scanf("%d%d%d",&u,&v,&w);
		ed[u].emplace_back(v,w);
		rev[v].emplace_back(u,w);
		ev.push_back({w,{u,v}});
	}
	dijk(ed,d1,s);
	dijk(rev,d2,t);
	//for(int i=1;i<=V;i++) printf("%d\n",d2[i]);
	for(int i=0;i<E;i++){
		u=ev[i].second.first,v=ev[i].second.second,w=ev[i].first;
		if(d1[u]==-1||d2[v]==-1||d1[u]==-1||d2[v]==-1) continue;
		int ret=d1[u]+d2[v]+w;
		if(ret>d1[t]) mn=min(mn,ret);
	}
	//for(int i:S) printf("%d\n",i);
	printf("%d",mn);
}
