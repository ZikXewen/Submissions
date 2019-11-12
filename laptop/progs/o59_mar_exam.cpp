#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 5e4 + 5;
map<int, int> mp;
vector<ii> q[X];
int N, M, ft[X], ar[X], an[10 * X];
void ud(int x, int va) { for(x++; x < X; x += -x & x) ft[x] += va; }
int qu(int x) {int re = 0; for(x++; x; x -= -x & x) re += ft[x]; return re;}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &ar[i]);
	scanf("%d", &M);
	for(int i = 0, u, v; i < M; i++) scanf("%d %d", &u, &v), q[v].emplace_back(u, i);
	for(int i = 0, te; i < N; i++){
		te = mp[ar[i]]; if(te--) ud(te, -1);
		ud(i, 1); mp[ar[i]] = i + 1;
		for(auto j: q[i]) an[j.y] = i - j.x - qu(i) + qu(j.x - 1) + 1;
	}
	for(int i = 0; i < M; i++) printf("%d\n", an[i]);
}
