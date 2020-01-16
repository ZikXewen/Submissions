#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e5 + 5;
int N, M, K, an[X >> 3], ft[X];
stack<int> ar[X], ad[X];
stack<ii> aq[X];
void ud(int po, int va) { for(po++; po < X; po += -po & po) ft[po] += va; }
int qu(int po) { int re = 0; for(po++; po; po -= -po & po) re += ft[po]; return re;}
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0, x1, y1, x2, y2; i < N; i++) scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x2++, y2++,
			ar[x1].emplace(y1), ad[x1].emplace(y2), ad[x2].emplace(y1), ar[x2].emplace(y2);
	for(int i = 0, x, y; i < M; i++) scanf("%d %d", &x, &y), aq[x].emplace(y, i);
	for(int i = 0; i < X; i++){
		while(ar[i].size()) ud(ar[i].top(), 1), ar[i].pop();
		while(ad[i].size()) ud(ad[i].top(), -1), ad[i].pop();
		while(aq[i].size()) an[aq[i].top().second] = qu(aq[i].top().first), aq[i].pop();
	}
	for(int i = 0; i < M; i++) printf("%d\n", an[i]);
}
