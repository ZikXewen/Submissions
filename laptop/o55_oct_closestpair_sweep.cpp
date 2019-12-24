#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
int N, fs;
long long an = LLONG_MAX;
vector<ii> ar;
set<ii, greater<ii>> s;
int main(){
	scanf("%d", &N);
	for(int i = 0, u, v; i < N; i++) scanf("%d %d", &u, &v), ar.emplace_back(u, v);
	sort(ar.begin(), ar.end());
	for(int i = 0; i < N; i++) {
		int te = ceil(sqrt(an));
		while(ar[i].x - ar[fs].x >= an) s.erase(ar[fs++]);
		auto en = s.upper_bound({0, ar[i].y + te});
		for(auto be = s.lower_bound({0, ar[i].y - te}); be != en; be++){
			int xx = be->first - ar[i].first, yy = be->second - ar[i].second;
			an = min(an, 1LL * xx * xx + 1LL * yy * yy);
		}
		s.emplace(ar[i]);
	} printf("%lld", an);
}
