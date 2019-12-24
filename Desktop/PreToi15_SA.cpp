#include<bits/stdc++.h>
using namespace std;
class ii{ public:
	int u,v,w,id;
	bool operator<(const ii &r)const{ return w>r.w; }
};
const int MXN = 1e5+5;
int sec,N,M,p[MXN],ty;
bool ck;
long long ret;
vector<int> an;
vector<ii> ed;
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
bool un(int u,int v){
	u=fd(u),v=fd(v);
	if(u==v) return 0;
	p[u]=v; return 1;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1,u,v,w;i<=M;i++) {scanf("%d%d%d",&u,&v,&w); ed.push_back({u,v,w,i});}
	for(int i=1;i<=N;i++) p[i]=i;
	sort(ed.begin(),ed.end());
	for(ii i:ed)
		if(un(i.u,i.v)) ret+=i.w,an.push_back(i.id);
		else if(!sec) sec=i.w,an.push_back(i.id);
	for(int i=1;i<=N;i++) if(fd(i)!=fd(1)) {ck=1; break;}
	scanf("%d",&ty);
	if(ck||!sec) printf("-1");
	else{
		ret+=sec;
		printf("%lld\n",ret);
		if(ty==2) for(int i:an) printf("%d ",i);
	}
}