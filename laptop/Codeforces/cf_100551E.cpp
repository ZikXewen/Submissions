#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 5e5 + 5;
class dsu{
	public:
	vector<bool> an;
	vector<int> p;
	vector<ii> g;
	vector<vector<ii>> lv, rv;
	stack<ii> rbp;
	int ct;
	dsu(int sz) : p(sz + 1) {}
	void setsz(int sz) {
		g.resize(sz); lv.resize(sz); rv.resize(sz); an.resize(sz);
	}
	void sol(int l = 0, int r = X - 1){
		if(l == r) return an[l] = (ct == p.size() - 1), void();

	}
};
vector<int> lef;
int N, M, Q;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	dsu one(N);
	for(int i = 0, u, v; i < M; ++i) cin >> u >> v, one.g.emplace_back(u, v);
	cin >> Q;
	one.setsz(Q);
	for(int i = 0, u; i < Q; ++i){
		cin >> u;
		for(int j = 0, v; j < u; ++j) {
			cin >> v;
			if(lef[v] != i)
				one.lv[i - 1].emplace_back(lef[v], v),
				one.rv[lef[v]].emplace_back(i - 1, v);
			lef[v] = i + 1;
		}
	}
	for(int i = 0; i < N; ++i)
		one.lv[Q].emplace_back(lef[i], i),
		one.rv[lef[i]].emplace_back(Q, i);
	one.sol();
}