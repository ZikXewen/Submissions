#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 1e5 + 5;
int N, M, Q;
vector<int> in[X], ot[X], an;
vector<ii> cn, ed;
bool no[X], one[X], lst[X];
void dfs_s(int u){
	one[u] = 1;
	for(int v: ot[u]) if(!no[v] && !one[v]) dfs_s(v);
}
void dfs_e(int u){
	lst[u] = 1;
	for(int v: in[u]) if(!no[v] && !lst[v]) dfs_e(v);
}
int main(){
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0, u, v; i < M; i++) scanf("%d %d", &u, &v), in[v].emplace_back(u), ot[u].emplace_back(v), ed.emplace_back(u, v);
	for(int i = 0, u, v; i < Q; i++){
		scanf("%d %d", &u, &v);
		cn.emplace_back(u, v);
		if(u == 1) no[v] = 1;
	} 
	reverse(cn.begin(), cn.end());
	dfs_s(1); dfs_e(N);
	for(ii i: cn){
		if(i.x == 1){
			no[i.y] = 0;
			for(int p: in[i.y]) if(one[p]) dfs_s(i.y);
			for(int p: ot[i.y]) if(lst[p]) dfs_e(i.y);
		}
		else an.emplace_back((one[i.y] && lst[i.y])? 1 : 0);
	}
	reverse(an.begin(), an.end());
	for(int i: an) printf("%d\n", i);
}
