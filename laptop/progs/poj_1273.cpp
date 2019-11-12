#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MXV = 205;
int V,E;
vector<bool> vst;
vector<int> par;
vector<vector<int> > ed,cap;
bool inp(){
	cap.assign(MXV,vector<int>(MXV,0));
	ed.assign(MXV,vector<int>());
	int u,v,w;
	if(scanf("%d%d",&E,&V)==EOF) return 0;
	for(int i=0;i<E;i++){
		scanf("%d%d%d",&u,&v,&w);
		cap[u][v]+=w; ed[u].push_back(v); ed[v].push_back(u);
	}
	return 1;
}
bool bfs(){
	par.assign(MXV,0);
	vst.assign(MXV,0);
	queue<int> q; q.push(1); vst[1]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=0;i<ed[x].size();i++) if(cap[x][ed[x][i]]&&!vst[ed[x][i]]){
			vst[ed[x][i]]=1; par[ed[x][i]]=x; q.push(ed[x][i]);
			if(ed[x][i]==V) return 1;
		}
	}
	return 0;
}
int FFEK(){
	int ans=0;
	while(bfs()){
		int tmp=V,mn=2e9+5;
		while(tmp!=1){
			mn=min(mn,cap[par[tmp]][tmp]);
			tmp=par[tmp]; 
		}
		ans+=mn; tmp=V;
		while(tmp!=1){
			cap[par[tmp]][tmp]-=mn;
			cap[tmp][par[tmp]]+=mn;
			tmp=par[tmp];
		}
	}
	return ans;
}
int main(){
	while(inp()) printf("%d\n",FFEK());
}
