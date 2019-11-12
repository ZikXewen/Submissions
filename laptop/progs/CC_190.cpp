#include<iostream>
#include<vector>
#define MX 100005
#define ui unsigned int
#define ii pair<ui,ui>
using namespace std;
ui n,m,a,b,low[MX],mem[MX],disc[MX],counter=0,out[MX];
bool brd[MX],vst[MX],pass[MX];
vector<ii> vec[MX],ed,bridge;
void tarjan(ui u, ui p) {
    low[u] = disc[u] = ++counter;
	for (auto i:vec[u]) {
    	ui v=i.first;
        if (!disc[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]){
            	pass[i.second]=true; bridge.push_back(i);
			}
        } else if(v != p) low[u] = min(low[u], disc[v]);
    }
}
void dfs(int cur){
	vst[cur]=true;
	for(auto i:vec[cur]){
		if(pass[i.second]||vst[i.first]) continue;
		dfs(i.first);
	}
}
ui dfsx(int cur){
	ui ret=0;
	vst[cur]=true;
	for(auto i:vec[cur]){
		if(pass[i.second]){
			if(vst[i.first]) ret+=mem[i.first];
			continue;
		}
		if(vst[i.first]) continue;
		ret+=dfsx(i.first);
	}
	return mem[cur]=ret+1;
}
int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		vec[a].push_back({b,i});
		vec[b].push_back({a,i});
		ed.push_back({a,b});
	}
	tarjan(1,0);
	dfs(1);
	for(ii i:bridge){
		ui tem=dfsx(i.first);
		out[i.second]=(n-tem)*tem;
	}
	for(int i=0;i<m;i++) cout << out[i] << ' ';
}

