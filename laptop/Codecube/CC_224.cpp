#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 6e5 + 5, MD = 1e9 + 7;
int N, M, mod[X] = {1}, p[X], cc;
int fd(int x){return p[x] = (p[x] == x)? x : fd(p[x]);}
void un(int u, int v){ if((u = fd(u)) != (v = fd(v))) p[u] = v, --cc; }
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i = 1; i < X; ++i) mod[i] = (mod[i - 1] << 1) % MD, p[i] = i;
	cin >> N >> M; cc = N << 1;
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		if(u) un(v, w), un(v + N, w + N);
		else un(v, w + N), un(v + N, w);
		if(fd(u) == fd(u + N) or fd(v) == fd(v + N)) {while(++i <= M) cout << "0\n"; break;}
		cout << mod[cc >> 1] << '\n';
	}
}