#include<bits/stdc++.h>
using namespace std;
const int MXV = 210;
const int MXQ = 310;
int V,Q,lvl[MXV],tab[MXV][int(log2(MXV))],mn=11;
bool cut[MXV],brk[MXQ],vst[MXQ];
vector<int> ed[MXV],ans;
class pr{
	public:
	int u,v,fu,fv;
	bool operator<(const pr &R){
		return lvl[fu]>lvl[R.fu];
	}
};
pr ls[MXQ];
void inp(){
	int u,v;
	scanf("%d%d",&V,&Q);
	for(int i=1;i<V;i++){
		scanf("%d%d",&u,&v);
		ed[u].emplace_back(v); ed[v].emplace_back(u);
	} V++;
	for(int i=0;i<Q;i++){
		scanf("%d%d",&u,&v);
		ls[i]={u,v,0,0};
	}
}
void pre(int u,int p){
	for(int i=1;i<=log2(V);i++) tab[u][i]=tab[tab[u][i-1]][i-1];
	for(int v:ed[u]) if(v!=p){
		lvl[v]=lvl[u]+1;
		tab[v][0]=u;
		pre(v,u);
	}
}
void lca(){
	int u,v;
	for(int i=0;i<Q;i++){
		u=ls[i].u,v=ls[i].v;
		if(lvl[u]<lvl[v]) swap(u,v);
		for(int i=log2(V);i>=0;i--) if(lvl[tab[u][i]]>lvl[v]) u=tab[u][i];
		if(tab[u][0]==v) {ls[i].fu=u; continue;}
		if(lvl[u]>lvl[v])u=tab[u][0];
		for(int i=log2(V);i>=0;i--) if(tab[u][i]!=tab[v][i]) {u=tab[u][i]; v=tab[v][i];}
		ls[i].fu=u; ls[i].fv=v;
	}
}
bool fill(int u,int p, int e){
	if(u==e) return true;
	for(int v:ed[u]) if(v!=p){
		if(lvl[v]<lvl[u]){if(cut[u]) continue;}
		else if(cut[v]) continue;
		if(fill(v,u,e)) return true;
	}
}
void dfs(int cur,int cnt){
	if(cnt>=mn) return;
	if(cur==Q){
		ans.clear(); mn=cnt;
		for(int i=0;i<V;i++) if(cut[i]) ans.emplace_back(i);
		return;
	}
	if(brk[cur]) {dfs(cur+1,cnt); return;}
	vector<int> jc;
	
	cut[ls[cur].fu]=1;
	/*flush*/ for(int i=0;i<Q;i++) if(!brk[i]&&!fill(ls[i].u,0,ls[i].v)) {
		brk[i]=1; jc.emplace_back(i);
	}
	dfs(cur+1,cnt+1);
	cut[ls[cur].fu]=0; 
	/*readd*/ for(int i:jc) brk[i]=0; jc.clear();
	
	if(!ls[cur].fv) return;
	
	cut[ls[cur].fv]=1;
	/*flush*/  for(int i=0;i<Q;i++) if(!brk[i]&&!fill(ls[i].u,0,ls[i].v)) {
		brk[i]=1; jc.emplace_back(i);
	}
	dfs(cur+1,cnt+1);
	cut[ls[cur].fv]=0;
	/*readd*/ for(int i:jc) brk[i]=0;
}
int main(){
	inp();
	pre(1,0);
	lca();
	sort(ls,ls+Q);
	//for(int i=0;i<Q;i++) printf("%d %d\n",ls[i].fu,ls[i].fv);
	dfs(0,0);
	printf("%d\n",mn);
	for(int i:ans) printf("%d %d\n",i,tab[i][0]);
}
/*
14 5
1 2
1 3
13 5
14 5
5 9
9 6
6 10
9 3
9 7
7 12
11 8
11 4
11 3
*/
