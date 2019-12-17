#include <bits/stdc++.h>
#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second
#define lint long long
using namespace std;
auto rcom = [](const ii &l, const ii &r){return l.yy < r.yy;};
int N, K;
lint sm, an = 1e18;
vector<ii> pt;
set<ii> st;
lint dis(ii l, ii r) {return 1ll * abs(l.xx - r.xx) + 1ll * abs(l.yy - r.yy);}
void insrt(ii x){
	if(st.empty()) {st.emplace(x); return;}
	auto it = st.lower_bound(x);
	if(it == st.begin()) sm += dis(*it, x); 
	else if(it == st.end()) sm += dis(*prev(it), x);
	else sm += dis(*it, x) + dis(*prev(it), x) - dis(*it, *prev(it));
	st.emplace(x);
}
void del(ii x){
	auto it = st.lower_bound(x);
	if(it == st.begin()) sm -= dis(*it, *next(it));
	else if(it == prev(st.end())) sm -= dis(*it, *prev(it));
	else sm -= dis(*it, *next(it)) + dis(*it, *prev(it)) - dis(*prev(it), *next(it));
	st.erase(it);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for(int i  = 0, u, v; i < N; ++i) cin >> u >> v, pt.emplace_back(u, v);
	if(K == 1) {cout << 0; return 0;}
	sort(all(pt), rcom);
	for(int i = 0; i < K; ++i) insrt(pt[i]); an = min(an, sm);
	for(int i = K; i < N; ++i) del(pt[i - K]), insrt(pt[i]), an = min(an, sm);
	cout << an;
}
