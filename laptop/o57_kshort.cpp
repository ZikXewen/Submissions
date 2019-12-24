#include <cstdio>
#include <queue>
#include <vector>
const int MXN = 10005;
using namespace std;
class ii{
public: int v,w,t;
	bool operator<(const ii &R)const{
		return w>R.w;
	}
};
int N,M,S,L,u,v,w;
bool vst[MXN][55];
vector<ii> ed[MXN];
int dijk(){
	priority_queue<ii> q;
	q.push({1,0,0});
	while(!q.empty()){ 
		ii x=q.top(); q.pop(); 
		if(vst[x.v][x.t]) continue;
		if(x.v==N) return x.w;
		vst[x.v][x.t]=true;
		for(ii i:ed[x.v]) if(x.t+i.t<=L&&!vst[i.v][x.t+i.t]) q.push({i.v,x.w+i.w,x.t+i.t});
	}
}
int main(){
	scanf("%d%d%d%d",&N,&M,&S,&L);
	for(int i=0;i<M;i++) {scanf("%d%d%d",&u,&v,&w); ed[u].push_back({v,w,0});}
	for(int i=0;i<S;i++) {scanf("%d%d%d",&u,&v,&w); ed[u].push_back({v,w,1});}
	printf("%d",dijk());
}
