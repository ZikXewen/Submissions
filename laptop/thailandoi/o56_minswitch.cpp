#include<bits/stdc++.h>
using namespace std;
const int MXV = 10005;
const int k = 20;
vector<int> ed[MXV];
vector<int> ans;
bool mrk[MXV];
int V,E,mn=k+1;
void inp(){
	int u,v;
	scanf("%d%d",&V,&E); V++;
	for(int i=0;i<E;i++){
		scanf("%d%d",&u,&v);
		ed[u].emplace_back(v);
		ed[v].emplace_back(u);
	}
}
void dfs(int cur,int cnt){ //cout << cur << ' ' << cnt << endl;
	if(cnt>=mn) return;
	if(cur==V){
		mn=cnt; ans.clear();
		for(int i=0;i<V;i++) if(mrk[i]) ans.emplace_back(i);
		return;
	}
	if(mrk[cur]) {dfs(cur+1,cnt); return;}
	if(ed[cur].size()>1){
		mrk[cur]=1;
		dfs(cur+1,cnt+1);
		mrk[cur]=0;
	}
	vector<int> tmp;
	if(ed[cur].size()<mn){
		for(int i:ed[cur]) if(!mrk[i]) {mrk[i]=1; tmp.emplace_back(i);}
		dfs(cur+1,cnt+tmp.size());
		for(int i:tmp) mrk[i]=0;
	}
}
int main(){
	inp();
	dfs(1,0);
	printf("%d",mn);
	for(int i:ans) printf("\n%d",i);
}
/*
5 6
1 2
2 3
4 3
5 3
1 3
5 1

7 9
1 2
2 3
1 3
3 4
4 5
5 6
6 3
3 7
7 6
*/
