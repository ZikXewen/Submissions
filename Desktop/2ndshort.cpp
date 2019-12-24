#include<bits/stdc++.h>
#define MXV 10005
using namespace std;
class lis{ public: int v,w; };
class edge{	public: int u,v,w; };
class comp{ public: bool operator()(lis L,lis R){return L.w>R.w;}};
int V,E,s,t,_u,_v,_w,dis[MXV],redis[MXV],ans=2e9;
vector<edge> ed;
vector<lis> pat[MXV],rev[MXV];
void dijk(int st,vector<lis> in[],int out[]){
	priority_queue<lis,vector<lis>,comp> q; q.push({st,0});
	while(!q.empty()){ 
		auto x=q.top(); q.pop();
		if(out[x.v]!=-1) continue;
		out[x.v]=x.w;
		for(auto i:in[x.v]) if(out[i.v]==-1) q.push({i.v,i.w+x.w});
	}
}
int main(){
	memset(dis,-1,sizeof dis);
	memset(redis,-1,sizeof redis);
	scanf("%d%d%d%d",&V,&E,&s,&t);
	for(int i=0;i<E;i++){
		scanf("%d%d%d",&_u,&_v,&_w);
		ed.push_back({_u,_v,_w}); pat[_u].push_back({_v,_w}); rev[_v].push_back({_u,_w});
	}
	dijk(s,pat,dis); dijk(t,rev,redis);
	for(auto i:ed){
		int cal=dis[i.u]+redis[i.v]+i.w;
		if(dis[i.u]!=-1&&redis[i.v]!=-1&&cal>dis[t]) ans=min(cal,ans); 
	}
	printf("%d",ans);
}