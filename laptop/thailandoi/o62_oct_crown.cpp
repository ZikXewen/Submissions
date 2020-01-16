#include <bits/stdc++.h>
#define lint long long
#define ii tuple<lint, lint, lint, lint>
using namespace std;
const int X = 2e5 + 5, Y = 1e6 + 5;
int N, h[X], p[X];
lint an = -1;
vector<int> up[Y];
bool vs[X], vs2[X];
ii dat[X];
int fd(int u){return p[u] = (p[u] == u)? u : fd(p[u]);}
void mrg(int l, int r){
	lint hu, su, fu, scu, hv, sv, fv, scv;
	tie(hu, su, fu, scu) = dat[l];
	tie(hv, sv, fv, scv) = dat[r];
	lint bot = min(hu, hv);
	fu = fu + ((hu - bot) * su); fv = fv + ((hv - bot) * sv);
	ii tem = ii(min(hu, hv), su + sv, max(fu, fv), max({min(fu, fv), scu, scv}));
	p[r] = l; dat[l] = tem;
}
void ud(int l, int r){
	for(int i = l; i <= r; i++) p[i] = l, vs[i] = 1;
	dat[l] = ii(h[l], r - l + 1, 0, 0);
	if(l > 0 && vs[l - 1]) mrg(fd(l - 1), l);
	if(r < N - 1 && vs[r + 1]) mrg(fd(l), r + 1);
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &h[i]), up[h[i]].emplace_back(i);
	iota(p, p + N, 0);
	for(int i = 1e6; i; i--){
		bool check = 0; int prv = -2, str = -2;
		for(int j: up[i]){
			if(j != prv + 1){
				if(check) ud(str, prv);
				check = 1;
				prv = str = j;
			}
			else prv++;
		}
		if(check) ud(str, prv);
	}
	for(int i = 0; i < N; i++) if(vs[i] && !vs2[fd(i)]){
		lint hh, s, f, sc;
		vs2[fd(i)] = 1;
		tie(hh, s, f, sc) = dat[fd(i)]; 
		if(sc) an = max(an, f + sc + (s * hh));
		else {
			int tem = 2e9;
			for(int j = fd(i) + 1; j + 1 < fd(i) + s; j++) if(h[j] != 1 && h[j - 1] != 1 && h[j + 1] != 1)
				tem = min(tem, abs(h[j] - min(h[j - 1], h[j + 1])) + 1);
			an = max(an, f + sc + (s * hh) - tem);
		}
	}
	printf("%lld", an);
}
