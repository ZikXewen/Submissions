#include <bits/stdc++.h>
using namespace std;
struct one{
	int u, v, id;
	bool operator<(const one &r){return u < r.u;}
	one(int _u, int _v, int _id) : u(_u), v(_v), id(_id) {}
};
const int X = 2e5 + 5;
int N, M, Q, ar[X], cur[X];
bool an[X];
vector<one> qu;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Q;
	for(int i = M + 1; i < X; ++i) cur[i] = X;
	for(int i = 1; i <= N; ++i) cin >> ar[i];
	for(int i = 0, u, v; i < Q; ++i) cin >> u >> v, qu.emplace_back(u, v, i);
	sort(qu.begin(), qu.end());
	int l = qu[0].u, r = qu[0].u - 1, ze = M;
	for(auto [u, v, id]: qu){
		while(l < u) if(!--cur[ar[l++]]) ++ze;
		while((r < N) and ze) if(!cur[ar[++r]]++) --ze;
		an[id] = (!ze and (v >= r));
	}
	for(int i = 0; i < Q; ++i) cout << (an[i]? "YES" : "NO") << '\n';
}