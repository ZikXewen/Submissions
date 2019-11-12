#include <cstdio>
#define MXN 1<<22
using namespace std;
int k,m,l,s,e,p[MXN],ct;
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
int main(){
	scanf("%d%d",&k,&m); k=1<<k;
	for(int i=0;i<=k;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&s);
		e=s+(1<<l);
		int u=fd(s),v=fd(e);
		if(u!=v){
			if(++ct==k) {printf("%d",i); return 0;}
			p[u]=v;
		}
	}
}
