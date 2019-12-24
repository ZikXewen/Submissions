#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;
const int X = 1e5 + 5;
int N, M, p[X], l[X], r[X];
vector<iii> ed, no;
vector<int> ck[X], an;
multiset<int> st;
int fd(int u){return p[u] = (p[u] == u) ? u: fd(p[u]);}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1, u, v, w; i <= M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if(i >= N) no.emplace_back(w, u, v), st.emplace(w); else ed.emplace_back(w, u, v);
	}
	int sz = no.size(); bool sti;
	fill_n(r, sz, ed.size() - 1);
	sort(ed.begin(), ed.end());
	do{
		iota(p, p + N + 1, 0); sti = 0;
		for(int i = 0; i < sz; i++) if(l[i] < r[i]) sti = 1, ck[(l[i] + r[i]) >> 1].emplace_back(i);
		for(int i = 0, u, v, w; i < ed.size(); i++){
			tie(w, u, v) = ed[i];
			p[fd(u)] = fd(v);
			for(int j: ck[i]){
				tie(w, u, v) = no[j];
				if(fd(u) == fd(v)) r[j] = i;
				else l[j] = i + 1;
			}
			ck[i].clear();
		}
	} while(sti);
	for(int i = 0; i < sz; i++){
		auto it = st.upper_bound(get<0>(ed[l[i]]));
		if(it == st.end()) return !printf("0");
		an.emplace_back(*it); st.erase(it);
	} printf("1");
	for(int i: an) printf("\n%d", i);
}
