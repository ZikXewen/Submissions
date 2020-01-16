#include <bits/stdc++.h>
#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std;
const int MX = 2e4 + 5;
int N, M, X, T, sz[MX]; ii sm[MX];
vector<ii> ar[MX];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> X >> T; --X;
	for(int i = 0; i <  N; ++i) cin >> sz[i], sm[i].y = i;
	for(int i = 0, u; i < N; ++i) for(int j = 0; j < M; ++j) cin >> u, ar[j].emplace_back(u, i);
	for(int i = 0; i < M; ++i){
		sort(all(ar[i]));
		for(int j = 0; j < N; ++j) sm[ar[i][j].y].x += sz[j];
	} sort(sm, sm + N, [](const ii &l, const ii &r){if(l.x == r.x) return l.y < r.y; return l.x > r.x;});
	for(int i = 0; i < N; ++i) if(sm[i].y == X) {cout << i + 1 << ' '; if(T == 2) cout << sm[i].x; break;}
}
