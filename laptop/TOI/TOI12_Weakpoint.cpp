#include<iostream>
#include<algorithm>
#include<vector>
#define MX 500005
using namespace std;
vector<int> ed[MX];
bool vst[MX];
int ct=0,low[MX],dist[MX],n,m,a,b,ans=MX;
void Input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ed[a].push_back(b); ed[b].push_back(a);
	}
}
void tarjan(int cur,int par){
	low[cur]=dist[cur]=++ct;
	for(int nxt:ed[cur]){
		if(dist[nxt]){
			low[cur]=min(low[cur],dist[nxt]);
			continue;
		}
		tarjan(nxt,cur);
		low[cur]=min(low[cur],low[nxt]);
		if(par!=0&&low[nxt]>=dist[cur]&&cur<ans){
			ans=cur;
		}
	}
}
void dfs(int cur){
	if(cur==ans) return;
	vst[cur]=true; ++ct;
	for(int i:ed[cur]) if(!vst[i]) dfs(i);
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	tarjan(m,0); ct=0;
	dfs(m);
	if(ans!=MX) cout << ans << '\n' << n-ct-1;
	else if(m==1) cout << "2\n0";
	else cout << "1\n0";
}
