#include<cstdio>
#include<cstring>
#define MXN 100005
using namespace std;
int N,v[MXN],T,ed[MXN],vst[MXN],a;
bool dfs(int x,int v){
	if(!ed[x]||ed[x]==x) return true;
	vst[x]=v;
	if(vst[ed[x]]==v) return false;
	if(vst[ed[x]]) return true;
	return dfs(ed[x],v);
}
int main(){
	scanf("%d",&T); while(T--){
		bool fnd=false;
		memset(v,0,sizeof v);
		memset(ed,0,sizeof ed);
		memset(vst,0,sizeof vst);
		scanf("%d",&N);
		for(int i=1;i<=N;i++) {scanf("%d",&a); if(a) v[a]=i;}
		for(int i=1;i<=N;i++) {scanf("%d",&a); if(a) ed[v[a]]=i;}
		for(int i=1;i<=N;i++) if(!vst[i]&&!dfs(i,i)){ printf("NO\n"); fnd=true; break;}
		if(!fnd) printf("YES\n");
	}
}
/*1 3 5 4 2
1 4 5 2 3*/