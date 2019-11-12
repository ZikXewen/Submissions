#include<bits/stdc++.h>
using namespace std;
class ii{public: int u; long long w;};
class iii{ public:
	int u,v; long long w;
	bool operator<(const iii &R){return this->w<R.w;}
};
long long sm;
int V,E;
vector<iii> lt,lft;
vector<int> pr,lvl;
vector<vector<ii>> ed,tab;
void inp(){
	int _u,_v,_w;
	scanf("%d%d",&V,&E);
	/*Init*/ed.resize(++V);  pr.resize(V);  lt.resize(E); for(int i=1;i<V;i++) pr[i]=i;
	for(int i=0;i<E;i++){
		scanf("%d%d%d",&_u,&_v,&_w);
		lt[i]={_u,_v,_w};
	}
}
int fd(int x){ if (pr[x]==x) return x; return pr[x]=fd(pr[x]); }
bool un(int x,int y){
	int _x=fd(x),_y=fd(y);
	if(_x==_y) return false;
	pr[_x]=_y; return true;
}
void mst(){
	sort(lt.begin(),lt.end());
	for(auto x:lt){
		if(un(x.u,x.v)) {ed[x.u].push_back({x.v,x.w});ed[x.v].push_back({x.u,x.w}); sm+=x.w;}
		else  lft.push_back(x);
	}
	/*Init*/ tab.assign(V,vector<ii>(log2(V)+1)); lvl.resize(V);
}
void pre(int u,int p){
	for(int i=1;i<=log2(V);i++){
		tab[u][i].u=tab[tab[u][i-1].u][i-1].u;
		tab[u][i].w=max(tab[u][i-1].w, tab[tab[u][i-1].u][i-1].w);
	}
	for(ii v:ed[u]) if(v.u!=p){
		lvl[v.u]=lvl[u]+1;
		tab[v.u][0].u=u;
		tab[v.u][0].w=v.w;
		pre(v.u,u);
	}
}
long long mx(int u,int v){
	long long ret=0;
	if(lvl[u]<lvl[v]) swap(u,v);
	for(int i=log2(V);i>=0;i--) 
		if(lvl[tab[u][i].u]>=lvl[v]) {
			ret=max(ret,tab[u][i].w);
			u=tab[u][i].u;
		}
	if(u==v) return ret;
	for(int i=log2(V);i>=0;i--) 
		if(lvl[tab[u][i].u]!=lvl[tab[v][i].u]) {
			ret=max(ret,max(tab[u][i].w,tab[v][i].w)); 
			u=tab[u][i].u; v=tab[v][i].u;
		}
	return max(ret,max(tab[u][0].w,tab[v][0].w));
}
void smst(){
	long long ans=9e18;
	for(auto i:lft){
		long long cur=sm-mx(i.u,i.v)+i.w;
		if(cur>sm) ans=min(cur,ans);
	}
	printf("%lld",ans);
}
int main(){
	inp();
	mst();
	pre(1,0);
	smst();
}
