#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>
#define MXV 200000
using namespace std;
vector<int> par;
vector<bool> ck;
vector<iii> ed;
vector<vector<ii>> ad;
vector<vector<int>> tab;
vector<int> nw,dsc,eu,dist;
int N,M,len,cnt;
idx(int x,int y){ return x*N+y; }
mrg(int x,int y,int va){ed.push_back({va,{x,y}});}
mrg1(int x,int y,int va){ad[x].emplace_back(va,y);ad[y].emplace_back(va,x);}
inp(){
	scanf("%d%d",&M,&N);
	par.resize(M*N); ad.resize(M*N);
	for(int i=0,_v;i<M;i++){
		for(int j=1;j<N;j++) {scanf("%d",&_v);  mrg(idx(i,j),idx(i,j-1),_v);}
		if(i+1<M) for(int j=0;j<N;j++){ scanf("%d",&_v); mrg(idx(i,j),idx(i+1,j),_v);}
	}
}
int fd(int x){
	if (par[x]==x) return x;
	return par[x]=fd(par[x]);
}
bool un(int x,int y){
	int xx=fd(x),xy=fd(y);
	if(xx==xy) return false;
	par[xx]=xy; return true;
}
mst(){
	for(int i=0;i<par.size();i++) par[i]=i;
	sort(ed.begin(),ed.end()); ck.resize(ed.size());
	for(int i=0;i<ed.size();i++) if(un(ed[i].second.first,ed[i].second.second)) {
		len+=ed[i].first; ck[i]=true;
		mrg1(ed[i].second.first,ed[i].second.second,ed[i].first);
	}
}
tour(int u,int p,int w){
	nw[u]=cnt++;
	dsc[u]=eu.size();
	eu.emplace_back(nw[u]);
	dist[nw[u]]=w;
	for(ii i:ad[u]){
		if(i.second== p) continue;
		tour(i.second,u,w+i.first);
		eu.emplace_back(nw[u]);
	}
}
pre(){
	tab.assign(log2(eu.size())+1,vector<int>(eu.size()));
	tab[0]=eu;
	for(int i=1;i<=log2(eu.size());i++) for(int j=0;j+(1<<i)<=eu.size();j++) tab[i][j]=min(tab[i-1][j],tab[i-1][j+(1<<(i-1))]);
}
path(int l,int r){
	int u=min(dsc[l],dsc[r]),v=min(dsc[l],dsc[r]),x=log2(v-u);
	
}
smst(){
	for(int i=0;i<ed.size();i++){
		if(ck[i]) continue;
		path(ed[i].second.first,ed[i].second.second);
	}
}
int main(){
	inp();
	mst();
	nw.resize(par.size()); dsc.resize(par.size()); dist.resize(par.size());
	tour(0,-1,0);
	//for(int i:eu) printf("%d ",i);
	pre();
	//smst();
}
