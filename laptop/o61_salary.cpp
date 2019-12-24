#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5+5;
const int MXC = 1e6+5;
int N,c[MXN],pr[MXN],ft[MXC],chd[MXN],lv[MXN];
vector<int> ed[MXN];
pair<int,int> srt[MXN];
void inp(){
	int u,v;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&c[i]);
	for(int i=1;i<N;i++) {scanf("%d%d",&u,&v); ed[u].emplace_back(v); ed[v].emplace_back(u);}
}
void flv(int u,int p){
	pr[u]=p; srt[u]={srt[p].first-1,u};
	for(int v:ed[u]) if(v!=p) flv(v,u);
}
void ud(int idx){
	for(;idx<=MXC;idx+=-idx&idx)  ft[idx]++;
}
int gt(int idx){
	//cout << idx;
	int ret=0;
	for(;idx;idx-=-idx&idx) {ret+=ft[idx]; }
	return ret;
}
/*void cchd(int u,int p){
	for(int v:ed[u]) {if(v!=p) cchd(v,u);}
	ud(c[u],1);
	chd[u]=gt(MXC)-gt(c[p]);
}*/
void dfs(int u,int p){
	if(c[u]<c[p]){
		
	}
}
int main(){
	inp();
	flv(0,0);
	sort(srt,srt+N);
	for(int i=0;i<N;i++){
		int u=srt[i].second;
		for(int v:ed[u]) if(v!=pr[u])ud(c[v]);
		chd[u]=gt(MXC)-gt(c[pr[u]]);
		if(c[pr[u]]<c[u]) chd[u]++;
	}
//	cout << ed[0].size();
//	for(int i:ed[0]) cout << i << endl<<endl;
//	cchd(0,0);
	dfs(0,0);
	for(int i=0;i<N;i++) cout << i << ' ' << pr[i] << endl;
	for(int i=0;i<N;i++) cout << srt[i].first << ' ' << srt[i].second << endl;
	for(int i=0;i<N;i++) cout << chd[i] << ' ';
}
