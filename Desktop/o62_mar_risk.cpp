#include <bits/stdc++.h>
#define ii pair<int, int>
#define lint long long
#define x first
#define y second
#define sback(x) *(x.end() - 2)
using namespace std;
int N, M, an;
vector<ii> p1, p2, h1, h2;
lint ori(ii w, ii u, ii v){return 1ll * (v.y - w.y) * (u.x - w.x) - 1ll * (v.x - w.x) * (u.y - w.y);}
lint dist(ii u, ii v){return 1ll * (v.y - u.y) * (v.y - u.y) + 1ll * (v.x - u.x) * (v.x - u.x);}
vector<ii> hull(vector<ii> ar){
	ii st = ar[0];
	for(ii i: ar) if(i.x < st.x || i.x == st.x && i.y < st.y) st = i;
	ar.erase(find(ar.begin(), ar.end(), st));
	vector<ii> re(1, st);
	sort(ar.begin(), ar.end(), [st](ii l, ii r){return ori(st, l, r) < 0;});
	for(ii i: ar){
		while(re.size() >= 2 && ori(sback(re), re.back(), i) > 0) re.pop_back();
		if(re.size() >= 2 && ori(sback(re), re.back(), i) == 0) {if(dist(sback(re), re.back()) < dist(sback(re), i)) re.pop_back(), re.emplace_back(i);}
		else re.emplace_back(i);
	} return re;
}
bool check(vector<ii> shp, ii pt){
	int l = 1, r = shp.size() - 1;
	if(ori(shp[0], shp[1], pt) > 0) return 0;
	while(l < r){
		int m = (l + r + 2) >> 1;
		if(ori(shp[0], shp[m], pt) <= 0) l = m;
		else r = m - 1;
	}
	return ori(shp[l], shp[(l + 1) % shp.size()], pt) <= 0;
}
int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0, u, v; i < N; i++) scanf("%d%d", &u, &v), p1.emplace_back(u, v);
	for(int i = 0, u, v; i < M; i++) scanf("%d%d", &u, &v), p2.emplace_back(u, v);
	h1 = hull(p1); h2 = hull(p2);
	for(ii i: p1) an += check(h2, i);
	for(ii i: p2) an += check(h1, i);
	printf("%d", an);
}
/*
8 4
0 0
2 2
1 0
0 1
2 0
0 2
1 2
2 1
-1 1
 1 1
1 -1
-1 -1
*/