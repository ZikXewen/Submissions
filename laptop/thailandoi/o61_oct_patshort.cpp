#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
#define lint long long
using namespace std;
int M, Q;
vector<ii> ar;
vector<pair<ii, ii>> ed;
lint ma(ii u, ii v){
	int dx = abs(u.x - v.x), dy = abs(u.y - v.y);
	return dx >= dy ? dx : (dy + ((dy - dx) & 1));
}
int main(){
	scanf("%d %d", &M, &Q);
	for(int i = 0, u, v, w, z; i < M; i++) scanf("%d %d %d %d", &u, &v, &w, &z),
		ar.emplace_back(u, v), ar.emplace_back(w, z), ed.emplace_back(ii(u, v), ii(w, z));
	sort(ar.begin(), ar.end());
	ar.resize(unique(ar.begin(), ar.end()) - ar.begin());
	vector<vector<lint>> di(ar.size(), vector<lint>(ar.size(), 2e9)); // unsure inf
	for(auto i: ed){
		int u = lower_bound(ar.begin(), ar.end(), i.x) - ar.begin(), 
		v = lower_bound(ar.begin(), ar.end(), i.y) - ar.begin();
		di[u][v] = di[v][u] = 1;
	}
	for(int i = 0; i < ar.size(); i++) di[i][i] = 0;
	for(int k = 0; k < ar.size(); k++) for(int i = 0; i < ar.size(); i++) for(int j = 0; j < ar.size(); j++)
		di[i][j] = min({di[i][j], di[i][k] + di[k][j], ma(ar[i], ar[j])});
	for(int i = 0, u, v, w, z; i < Q; i++){
		scanf("%d %d %d %d", &u, &v, &w, &z);
		lint an = ma(ii(u, v), ii(w, z));
		for(int i = 0; i < ar.size(); i++) for(int j = 0; j < ar.size(); j++) an = min(an, ma(ii(u, v), ar[i]) + di[i][j]+ ma(ii(w, z), ar[j]));
		printf("%lld\n", an);
	}
}
