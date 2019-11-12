#include <bits/stdc++.h>
using namespace std;
const int _N = 105;
class ii{ public:
	int v,w;
	ii(int vv,int ww){v=vv,w=ww;}
};
class iii{ public:
	int v,w,k; bool us;
	iii(int vv,int ww,int kk,bool uu) {v=vv,w=ww,k=kk; us=uu;}
	bool operator<(const iii &R)const{return k>R.k;}
};
int N,M,S,D,F;
int v[_N];
bool vst[_N][_N][2];
vector<ii> ed[_N];
void dijk(){
	priority_queue<iii> q;
	q.emplace(S,0,0,0);
	while(!q.empty()){
		auto x=q.top(); q.pop();
		if(vst[x.v][x.w][x.us]) continue; vst[x.v][x.w][x.us] = 1;
		if(x.v==D&&x.w==F) {printf("%d",x.k); return;}
		if(!x.us) q.emplace(x.v,F,x.k,1);
		for(int i=x.w+1;i<=F;i++) if(!vst[x.v][i][x.us]) q.emplace(x.v,i,x.k+(i-x.w)*v[x.v],x.us);
		for(auto i:ed[x.v]) if(i.w<=x.w&&!vst[i.v][x.w-i.w][x.us]) q.emplace(i.v,x.w-i.w,x.k,x.us);
	}
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	scanf("%d%d%d%d",&S,&D,&F,&M);
	for(int i=0,u,v,w;i<M;i++) scanf("%d%d%d",&u,&v,&w), ed[u].emplace_back(v,w), ed[v].emplace_back(u,w);
	dijk();
}
