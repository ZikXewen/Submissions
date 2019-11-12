#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, cd[X], cur[X], bk[X];
vector<int> ar[X];
set<int> s[X];
void ud(set<int> &de, int cr){
	if(cr == 0) return;
	int id = 0;
	for(int i: ar[cr]) if(de.find(i) == de.end()) ar[cr][id++] = i;
	ar[cr].resize(id);
	ud(de, cd[cr]);
}
void prt(int cr){
	if(cr == 0) return;
	for(int i: ar[cr]) printf("%d\n",i);
	prt(cd[cr]);
}
int main(){
	scanf("%d %d", &N, &M);
	iota(cur, cur + N, 0); iota(bk, bk + N, 0);
	for(int i = 0, u; i < N; i++){
		scanf("%d", &u);
		for(int j = 0, v; j < u; j++) scanf("%d", &v), ar[i].emplace_back(v);
	} 
	for(int j = 0, u, v, w; j < M; j++){
		scanf("%d %d %d", &u, &v, &w);
		if(u == 1) if(cur[v]) s[v].emplace(w);
		else{
			ud(s[cur[v]], cur[v]); ud(s[cur[w]], cur[w]);
			if(!cur[w]) continue;
			if(cur[v]) cd[bk[v]] = cur[w], bk[v] = bk[w], cur[w] = 0, bk[w] = 0;
			else cur[v] = cur[w], bk[v] = bk[w], cur[w] = 0, bk[w] = 0;
		}
	}
	for(int i = 0; i <= N; i++) ud(s[cur[i]], cur[i]), prt(cur[i]);
}
