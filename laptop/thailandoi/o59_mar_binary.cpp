#include <bits/stdc++.h>
using namespace std;
int N; vector<int> g[100005];
int dfs(int u, int v = 0){
	priority_queue<int, vector<int>, greater<int>> s;
	for(int i: g[u]) s.emplace(dfs(i));
	while(s.size() > 2) s.pop(), v = s.top(), s.pop(), s.emplace(v + 1);
	while(s.size()) v = s.top(), s.pop();
	return g[u].empty()? 0 : v + 1;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; for(int i = 2, u; i <= N; ++i) cin >> u, g[u].emplace_back(i);
	cout << dfs(1);
}
