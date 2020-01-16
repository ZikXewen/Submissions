#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;
const int X = 2e4 + 5;
int N, M, p[X], an = 2e9;
vector<iii> ed, us, un;
vector<int> ck[X];
bool ud;
int fd(int u) { return p[u] = p[u] == u? u : fd(p[u]); }
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), ed.emplace_back(w, u, v);
	iota(p, p + N, 0); sort(ed.begin(), ed.end());
	for(auto i: ed) {
		int u, v, w; tie(w, u, v) = i;
		int uu = fd(u), vv = fd(v);
		if(uu == vv) un.emplace_back(i);
		else p[uu] = vv, us.emplace_back(i);
	}
	vector<int> l(un.size()), r(un.size(), us.size() - 1);
	do {
		ud = 0; iota(p, p + N, 0);
		for(int i = 0; i < un.size(); i++) if(l[i] < r[i]) ud = 1, ck[(l[i] +r[i]) >> 1].emplace_back(i);
		for(int i = 0; i < us.size(); i++) {
			int u, v, w; tie(w, u, v) = us[i];
			p[fd(u)] = fd(v);
			for(int j: ck[i]) 
				if(fd(get<1>(un[j])) == fd(get<2>(un[j]))) r[j] = i;
				else l[j] = i + 1;
			ck[i].clear();
		}
	} while(ud);
	for(int i = 0; i < un.size(); i++) an = min(an, get<0>(un[i]) - get<0>(us[l[i]]));
	printf("%d", an + 1);
}
