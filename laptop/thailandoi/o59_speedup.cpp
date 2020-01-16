#include<cstdio>
#include<queue>
#include<vector>
#define pi pair<int,int>
#define MXN 80005
#define MXQ 10
using namespace std;
class ii{
public:
	int cur,pot,prev;
	long long walk;
	bool operator<(const ii&R)const{
		return walk>R.walk;
	}
};
int u,v,w,N,M,L,Q;
bool ch[MXN],vst[MXN][MXQ];
vector<pi> ed[MXN];
long long dijk(int st){
	priority_queue<ii> q;
	q.push({st,0,0,0});
	while(!q.empty()){
		 ii x=q.top(); q.pop();
		 if(vst[x.cur][x.pot]) continue;
		 vst[x.cur][x.pot]=true;
		 if(x.cur==N) return x.walk;
		 if(ch[x.cur]&&x.pot<Q&&x.prev!=x.cur) {x.pot++; x.prev=x.cur;};
		 for(pi i:ed[x.cur]) if(!vst[i.second][x.pot])  q.push({i.second,x.pot,x.prev,x.walk+(i.first/(1<<x.pot))});
	}
}
int main(){
	scanf("%d%d%d%d",&N,&M,&L,&Q);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		ed[u].emplace_back(w,v);
	}
	while(L--) {scanf("%d",&u); ch[u]=true;}
	printf("%lld",dijk(1));
}