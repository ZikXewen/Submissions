#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
bool comp(point &l, point &r){return l.real() < r.real() or (l.real() == r.real() and l.imag() < r.imag());}
double cp(point a, point b){return imag(conj(a) * b);}
bool cw(point a, point b, point c){return cp(b - a, c - b) < 0;}
bool ccw(point a, point b, point c){return cp(b - a, c - b) > 0;}
void bd(vector<point> &ar){
	sort(ar.begin(), ar.end(), comp);
	ar.resize(unique(ar.begin(), ar.end()) - ar.begin());
	if(ar.size() < 2) return;
	point p1 = ar.front(), p2 = ar.back();
	vector<point> up, dn;
	up.emplace_back(p1);
	dn.emplace_back(p1);
	for(int i = 1; i < ar.size(); ++i){
		if(i == ar.size() - 1 or cw(p1, ar[i], p2)){
			while(up.size() >= 2 and !cw(up[up.size() - 2], up[up.size() - 1], ar[i]))
				up.pop_back();
			up.emplace_back(ar[i]);
		}
		if(i == ar.size() - 1 or ccw(p1, ar[i], p2)){
			while(dn.size() >= 2 and !ccw(dn[dn.size() - 2], dn[dn.size() - 1], ar[i]))
				dn.pop_back();
			dn.emplace_back(ar[i]);
		}
	}
	dn.pop_back(); reverse(dn.begin(), dn.end()); dn.pop_back();
	ar.clear();
	for(auto u: up) ar.emplace_back(u);
	for(auto u: dn) ar.emplace_back(u);

	reverse(ar.begin(), ar.end());
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int N; vector<point> ar;
	while((cin >> N) and N){
		for(int i = 0, u, v; i < N; ++i) cin >> u >> v, ar.emplace_back(u, v);
		bd(ar);
		cout << ar.size() << '\n'; for(auto i: ar) cout << i.real() << ' ' << i.imag() << '\n';
		ar.clear();
	}
}