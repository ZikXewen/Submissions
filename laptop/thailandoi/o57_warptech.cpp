#include <cstdio>
#include <vector>
#include <algorithm>
#define MXN 5005
#define MXM 100005
using namespace std;
class ii{
public:
	int u,v,w;
	bool operator<(const ii &R)const{
		return w<R.w;
	}
};
int N,M,Q,p[MXN],ar[MXN],ct;
ii v[MXM];
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
bool ud(int s,int e){
	int x=fd(s),y=fd(e);
	if(x==y) return false;
	p[x]=y; return true;
}
int main(){
	scanf("%d%d%d",&N,&M,&Q); ct=N-1;
	for(int i=1;i<=N;i++) p[i]=i;
	for(int i=0;i<M;i++) scanf("%d%d%d",&v[i].u,&v[i].v,&v[i].w);
	sort(v,v+M);
	for(int i=0;i<M;i++) if(ud(v[i].u,v[i].v)) ar[ct--]=v[i].w;
	while(Q--){
		scanf("%d",&M);  printf("%d\n",ar[M]);
	}
}
