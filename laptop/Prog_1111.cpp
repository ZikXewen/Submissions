#include<cstdio>
#include<vector>
#include<queue>
#define ii pair<int,int>
#define MXN 100005
using namespace std;
vector<ii> v[MXN];
int vst[MXN],ans,N,s,e,mx,w;
void dijk(int st){
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push({1,st});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(vst[x.second]) continue; vst[x.second]=x.first;
		for(ii i:v[x.second]) if(!vst[i.first]) q.push({x.first+i.second,i.first});
	}
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		scanf("%d%d%d",&s,&e,&w);
		v[s].push_back({e,w});
		v[e].push_back({s,e});
	}
	dijk(1);
	for(int i=1;i<=N;i++) if(vst[i]>mx){
		mx=vst[i]; ans=i;
	}
	printf("%d",mx-1);
}
