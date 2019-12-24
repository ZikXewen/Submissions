#include<cstdio>
#include<algorithm>
#define MXN 1003
#define MXM 300005
using namespace std;
class iii{
	public:
		int u,v,w;
};
bool comp(iii L,iii R){
	return L.w<R.w;
}
int T,P,N,M,p[MXN],sm;
iii v[MXM];
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
bool un(int s,int e){
	int u=fd(s),v=fd(e);
	if(u==v) return false;
	p[u]=v; return true;
}
int main(){
	scanf("%d",&T); while(T--){
		scanf("%d%d%d",&P,&N,&M);
		for(int i=1;i<=N;i++) p[i]=i;
		for(int i=0;i<M;i++) scanf("%d%d%d",&v[i].u,&v[i].v,&v[i].w);
		sort(v,v+M,comp);
		for(int i=0;i<M;i++) if(un(v[i].u,v[i].v)) sm+=v[i].w;
		printf("%d",sm*P);
	}
}
