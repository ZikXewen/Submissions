#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
//#include<iostream>
#define INF 1<<30
#define ii pair<int,int>
#define MXN 505
using namespace std;
int N,M,S,D,dist[MXN];
vector<ii> adj[MXN],radj[MXN];
void dijk(vector<ii> adj[], int st){
	priority_queue<ii,vector<ii>,greater<ii> > q;
	memset(dist,-1,sizeof dist);
	q.push({0,st});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(dist[x.second]!=-1) continue;
		dist[x.second]=x.first;
		for(ii i:adj[x.second])	if(dist[i.first]==-1) q.push({x.first+i.second,i.first});
	}
}
void del(int ans){
	queue<ii> q;
	q.push({D,0});
	while(!q.empty()){
		ii x=q.front(); q.pop();
		for(auto i=radj[x.first].begin();i!=radj[x.first].end();i++) if(dist[i->first]+x.second+i->second==ans){
			q.push({i->first,x.second+i->second});
			i->second=INF;
		}
	}
}
int main(){
	int st,ed,we;
	while(scanf("%d%d",&N,&M)&&(N||M)){
		for(int i = 0; i < N; i++) {
			adj[i].clear(); radj[i].clear();
		}
		scanf("%d%d",&S,&D);
		while(M--){
			scanf("%d%d%d",&st,&ed,&we);
			adj[st].push_back({ed,we});
			radj[ed].push_back({st,we});
		}
		dijk(adj, S);
		//for(int i=0;i<N;i++) printf("%d\n",dist[i]);
		del(dist[D]);
		dijk(radj, D);
		if(dist[S]<INF&&dist[S]>0) printf("%d\n",dist[S]);
		else printf("-1\n");
	}
}
