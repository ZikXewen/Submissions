#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
struct one{
	vector<int> ar;
	stack<ii> stk;
	bool ok;
	one () {}
	one (int sz, int va) : ar(vector<int>(sz, va)) {};
	int sz() { return stk.size(); }
	void put(int po, int va){ stk.emplace(po, ar[po]); ar[po] = va; }
	void rb(int sz, bool ook) { while(stk.size() > sz) {auto [u, v] = stk.top(); stk.pop(); ar[u] = v;} ok = ook; }
	int fd(int x) { return (ar[x] < 0)? x : fd(ar[x]); }
	void un(ii k){
		int u = fd(k.first), v = fd(k.second);
		if(u == v) return;
		if(ar[u] > ar[v]) swap(u, v);
		put(v, u); put(u, ar[u] + ar[v]);
	}
} dsu;
vector<ii> ed, rgt[X], lft[X];
int N, M, K, C;
map<int, int> st;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 1, u, v; i <= M; ++i){
		cin >> u >> v; ii p(u, v);
		ed.emplace_back(p);
	}
	cin >> K;
	dsu = one(N + 1, -1);
	for(int i = 1, ct = M, u; i <= K; ++i) {
		cin >> C;
		for(int j = 0; j < C; ++j){
			cin >> u;
			rgt[i].emplace_back(st[u], u);
			if(i < K) lft[st[u]].emplace_back(i + 1, u);
			st[u] = i + 1;
		}
	}
	for(int i = 1; i <= M; ++i) if(st[i] <= K) rgt[K + 1].emplace_back(st[i], i), lft[st[i]].emplace_back(K + 1, i);
	sol(0, K + 1, 0);
}
