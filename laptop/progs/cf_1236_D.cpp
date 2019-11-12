#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int X = 1e5 + 5;
int N, M, K;
int t, b, l, r, di;
long long ct;
vector<ii> x, y;
ii te;
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0, u, v; i < K; i++) scanf("%d %d", &u, &v), x.emplace_back(--u, --v), y.emplace_back(u, v);
	sort(x.begin(), x.end()); sort(y.begin(), y.end(), [](ii ll, ii rr){if(ll.se != rr.se) return ll.se < rr.se; return ll.fi < rr.fi; });
	b = N, r = M;
	while(l < r || t < b){
		cout << t << ' ' << b << ' ' << l << ' ' << r << '\n';
		switch(di){
			case 0:
			te = *lower_bound(x.begin(), x.end(), ii(t, l));
			r = ((te.fi == t)? min(te.se, r) : r) - 1;
			ct += r - l + 1;
			break;
			case 1:
			te = *lower_bound(y.begin(), y.end(), ii(t, r));
			b = ((te.se == r)? min(te.fi, b) : b) - 1;
			ct += b - t + 1;
			break;
			case 2:
			te = *(upper_bound(x.begin(), x.end(), ii(b, r)) - 1);
			l = ((te.fi == b)? max(te.se, l) : l) + 1;
			ct += r - l + 1;
			break;
			default:
			te = *(upper_bound(y.begin(), y.end(), ii(b, l)) - 1);
			t = ((te.se == l)? max(te.fi, t) : t) + 1;
			ct += b - t + 1; 
		}
		di = (di + 1) % 3;
//		cout << te.fi << ' ' << 	te.se << '\n';
	}
	cout << ct;
}
