#include <cstdio>
#include <queue>
#include <vector>
#define MXN 50005
#define MXL 35
#define pii pair<int,int>
using namespace std;
class ii{
public:
	int wal,cur,pot;
	bool operator<(const ii& R)const{
		return wal>R.wal;
	}
};
int N,M,L,S,T,u,v,w,vec[MXN];
bool vst[MXN][MXL];
vector<pii> ed[MXN];
priority_queue<ii> q;
int main(){
	scanf("%d%d%d%d%d",&N,&M,&L,&S,&T);
	for(int i=1;i<=N;i++) scanf("%d",&vec[i]);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		ed[u].emplace_back(v,w);
	}
	q.push({0,S,0});
	while(!q.empty()){ 
		ii x=q.top(); q.pop();
		if(vst[x.cur][x.pot]) continue;
		if(x.cur==T&&x.pot==L){
			printf("%d",x.wal);
			return 0;
		}
		vst[x.cur][x.pot]=true;
		if(vec[x.cur]==x.pot) x.pot++;
		for(pii i:ed[x.cur]) if(!vst[i.first][x.pot])  q.push({x.wal+i.second,i.first,x.pot});
	}
	printf("-1");
}