#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 2e5 + 5;
int N, M, an;
vector<ii> b;
multiset<int> ar;
int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0, u; i < N; ++i) scanf("%d", &u), ar.emplace(u);
	for(int i = 0, u, v; i < M; ++i) scanf("%d%d", &u, &v), b.emplace_back(u - v, u + v);
	sort(b.begin(), b.end(), [](ii l, ii r){return l.y < r.y;});
	for(ii i: b){
		auto it = ar.lower_bound(i.x);
		if(it != ar.end() && *it <= i.y) ++an, ar.erase(it);
	}
	printf("%d", an);
}