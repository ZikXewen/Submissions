#include "traffic.h"
#include"trafficlib.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, ii> ip;
int _dist(ii a, ii b){return abs(a.first - b.first) + abs(a.second - b.second);}
vector<ip> ans;
void f(ii s, ii t, int k){
	if (_dist(s, t) == 1) {
		ans.push_back(ip(s, t));
		return;
	}
	ii m = {(s.first + t.first)/2, (s.second+t.second)/2};
	int v = traffic_query(s.first, s.second, m.first, m.second);
	if (v == _dist(s, m)) f(m, t, k);
	else if (v == _dist(s, m) + k) f(s, m, k);
	else if (v < _dist(s, m) +k) { f(s, m, k-1); f(m, t, k-1); }
}
int main(){
	int n, k;
	traffic_init(&n, &k);
	for (int i = 1; i <= n; i++) {
		int x = traffic_query(i, 1, i, n);
		if (x > n-1) f(ii(i, 1), ii(i, n), x - (n-1));
		int y = traffic_query(1, i, n, i);
		if (y > n-1) f(ii(1, i), ii(n, i), y- (n-1));
	}
	if (ans.size() == 1) ans.push_back(ip(ii(0, 0), ii(0, 0)));
	traffic_report(ans[0].first.first, ans[0].first.second, ans[0].second.first, ans[0].second.second, ans[1].first.first, ans[1].first.second, ans[1].second.first, ans[1].second.second );	
}
