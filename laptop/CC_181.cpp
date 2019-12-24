#include<iostream>
#include<vector>
#include<cstring>
#define MX 40005
#define MXV 1000000001
#define ii pair<int,int>
using namespace std;
int a,b,c,n,m,p,vst[MX];
vector<ii> ed[MX],qu;
void Input(){
	cin >> n >> m >> p;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		ed[a].push_back({c,b});
		ed[b].push_back({c,a});
	}
	for(int i=0;i<p;i++){
		cin >> a >> b;
		qu.push_back({a,b});
	}
}
void dfs(int cur,int x,int k){
	vst[cur]=x;
	for(ii i:ed[cur]) if(i.first<k&&!vst[i.second]) dfs(i.second,x,k);
}
bool chk(int cur){
	memset(vst,0,sizeof vst); int ct=0;
	for(int i=0;i<n;i++) if(!vst[i]) dfs(i,++ct,cur);
	for(auto i:qu) if(vst[i.first]==vst[i.second]) return false;
	return true;
}
int b_search(int st,int ed){
	if(st>ed) return ed;
	int md=(st+ed)/2;
	if(chk(md)) return b_search(md+1,ed);
	return b_search(st,md-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	int tem=b_search(1,MXV);
	if(tem==MXV) cout << -1;
	else cout << tem;
}
