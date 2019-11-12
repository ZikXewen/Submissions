#include <cstdio>
#include <map>
#include <cmath>
#define ii pair<int,int>
#define MXN 805
using namespace std;
int M,Q,a,b,c,d,ct,ed[MXN][MXN],tem;
ii v[MXN],l[MXN];
map<ii,int> m;
int cal(ii u,ii v){
	int dx=abs(u.first-v.first),dy=abs(u.second-v.second);
	if(dy>dx&&abs(dy-dx)&1) return dy+1;
	return max(dx,dy);
}
int sp(){
	for(int k=1;k<=ct;k++) for(int i=1;i<=ct;i++) for(int j=1;j<=ct;j++) ed[i][j]=min(ed[i][j],ed[i][k]+ed[k][j]);
}
int main(){
	scanf("%d%d",&M,&Q);
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x=m[{a,b}],y=m[{c,d}];
		if(!x) {x=m[{a,b}]=++ct; v[ct]={a,b};}
		if(!y) {y=m[{c,d}]=++ct; v[ct]={c,d};}
		ed[x][y]=ed[y][x]=1;
	}
	for(int i=0;i<Q;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x=m[{a,b}],y=m[{c,d}];
		if(!x) {x=m[{a,b}]=++ct; v[ct]={a,b};}
		if(!y) {y=m[{c,d}]=++ct; v[ct]={c,d};}
		l[i]={x,y};
	}
	//for(auto i:m) printf("%d %d %d\n",i.first.first,i.first.second,i.second); printf("\n");
	for(int i=1;i<=ct;i++) for(int j=1;j<i;j++){
		tem=cal(v[i],v[j]);
		if(!ed[i][j]) ed[i][j]=tem;
		if(!ed[j][i]) ed[j][i]=tem;
	}
	sp();
	for(int i=0;i<Q;i++) printf("%d\n",ed[l[i].first][l[i].second]);
	//for(int i=1;i<=ct;i++) {for(int j=1;j<=ct;j++) printf("%d ",ed[i][j]); printf("\n");}
}
