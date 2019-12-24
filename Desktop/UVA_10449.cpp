#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#define MXN 205
#define INF 1<<30
#define ii pair<int,int>
using namespace std;
int N,M,Q,T,a,b,v[MXN];
vector<ii> adj[MXN];
int dist[MXN]; 
void spfa(int st){
	int cnt[205]={};
	bool inq[205]={},neg[205]={};
	queue<int> q;
	dist[st]=0;
	q.push(st);
	while(!q.empty()){
		int x=q.front(); q.pop();
		inq[x]=0;
		for(auto i:adj[x]){
			int u=i.first,v=i.second;
			if(dist[u]>dist[x]+v){
				dist[u]=dist[x]+v;
				if(inq[u]==0){
					if(++cnt[u]>=N+1){
						queue<int> p;
						p.push(x);
						neg[x]=1;
						while(!p.empty()){
							int y=p.front();
							p.pop();
							dist[y]=-INF;
							for(auto i:adj[y]){
								if(neg[i.first]==0){
									neg[i.first]=1;
									p.push(i.first);
								}
							}
						}
					}
					if(neg[u]==0){
						q.push(u);
						inq[u]=1;
					}
				}
			}
		}
	}
}
int main(){
//	freopen("inp.txt","r",stdin);
//	freopen("file.txt","w",stdout);
	while(scanf("%d",&N)==1){
		for(int i=1;i<=N;i++){
			adj[i].clear();
			scanf("%d",&v[i]);
			dist[i]=INF;
		}
		scanf("%d",&M);
		while(M--){
			scanf("%d%d",&a,&b);
			adj[a].push_back({b,(v[b]-v[a])*(v[b]-v[a])*(v[b]-v[a])});
		}
		scanf("%d",&M);
		spfa(1);
		printf("Set #%d\n", ++T);
		while(M--){
			scanf("%d",&Q);
			if(dist[Q]<3||dist[Q]==INF) printf("?\n");
			else
				printf("%d\n",dist[Q]); 
		}
	}
//	fclose(stdin);
//	fclose(stdout);
}
