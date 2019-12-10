#include <bits/stdc++.h>
using namespace std;
const int X = 12e4 + 5;
int N, M, Q, roo, upd[X], sum[X];
vector<int> ar[X], rev[X];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Q; roo = sqrt(M);
	for(int i = 1, L; i <= M; ++i){
		cin >> L;
		for(int j = 0, u; j < L; ++j){
			cin >> u;
			if(L <= roo) ar[i].emplace_back(u);
			else rev[u].emplace_back(i);
		}
	}
	for(int z = 0, ty, u, v; z < Q; ++z){
		cin >> ty;
		if(ty == 1){
			cin >> u >> v;
			int chn = v - upd[u]; upd[u] = v;
			if(ar[u].size()) for(int i: ar[u]) sum[i] += chn;
		} else {
			cin >> u; int sm = 0;
			for(int i: rev[u]) sm += upd[i];
			cout << sm + sum[u] << '\n';
		}
	}
}