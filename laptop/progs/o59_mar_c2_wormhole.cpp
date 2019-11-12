#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
int K, Q;
vector<ii> pt;
vector<pair<ii, ii>> ho;
int ca(ii u, ii v){ return abs(u.x - v.x) + abs(u.y - v.y); }
int main(){
	scanf("%d %d", &K, &Q);
	for(int i = 0, u, v, w, z; i < K; i++) scanf("%d %d %d %d", &u, &v, &w, &z), 
		pt.emplace_back(u, v), pt.emplace_back(w, z),
		ho.emplace_back(ii(u, v), ii(w, z));
	sort(pt.begin(), pt.end());
	pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
	vector<vector<int>> di(pt.size(), vector<int>(pt.size(), 1e9));
	for(auto i: ho){
		int u = lower_bound(pt.begin(), pt.end(), i.x) - pt.begin(),
		v = lower_bound(pt.begin(), pt.end(), i.y) - pt.begin();
		di[u][v] = di[v][u] = 0;
	}
	for(int i = 0; i < pt.size(); i++) di[i][i] = 0;
	for(int k = 0; k < pt.size(); k++) for(int i = 0; i < pt.size(); i++) for(int j = 0; j < pt.size(); j++)
		di[i][j] = min({di[i][j], di[i][k] + di[k][j], ca(pt[i], pt[j])});
	for(int i = 0, u, v, w, z, an; i < Q; i++){
		scanf("%d %d %d %d", &u, &v, &w, &z);
		an = ca(ii(u, v), ii(w, z));
		for(int j = 0; j < pt.size(); j++) for(int k = 0; k < pt.size(); k++) an = min(an, ca(ii(u, v), pt[j]) + di[j][k] + ca(pt[k], ii(w, z)));
		printf("%d\n", an);
	}
}
