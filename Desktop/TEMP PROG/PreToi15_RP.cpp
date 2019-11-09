#include<bits/stdc++.h>
using namespace std;
class ii{public:
	int f; long long g;
	bool operator<(const ii &R)const{
		return g>R.g;
	}
};
const int MXN = 1e5+5;
int N,M,A,B,C,D;
bool al[MXN],vst[MXN];
long long d1[MXN],d2[MXN],d3[MXN];
vector<ii> ed[MXN];
void dijk(int s,long long *dis){
	memset(vst,0,sizeof vst);
	priority_queue<ii> q;
	q.push({s,0});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(vst[x.f]) continue;
		vst[x.f]=1; dis[x.f]=x.g;
		for(ii i:ed[x.f]) if(!vst[i.f]&&!al[i.f]) q.push({i.f,x.g+i.g});
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0,u,v,w;i<M;i++){
		scanf("%d%d%d",&u,&v,&w);
		ed[u].push_back({v,w});
		ed[v].push_back({u,w});
	}
	scanf("%d%d%d%d",&A,&B,&C,&D);
	dijk(A,d1);
	dijk(B,d2);
	for(int i=0;i<=N;i++) if(d1[i]+d2[i]==d1[B]) al[i]=1;
	dijk(C,d3);
	if(d3[D]) printf("%lld",d3[D]);
	else printf("-1");
}