#include <bits/stdc++.h>
using namespace std;
class pt{
	public: int u, v, w, z;
	pt(int _u, int _v, int _w, int _z) {u = _u, v = _v, w = _w, z = _z;}
};
vector<pt> ed;
int N, ar[2][2];
bool fd[50005];
int main(){
	scanf("%d", &N);
	for(int i = 1, u, v, w; i <= N; i++) scanf("%d %d %d", &u, &v, &w), ed.emplace_back(u, v, w, i);
	sort(ed.begin(), ed.end(), [](pt l, pt r){
		if(l.u != r.u) return l.u < r. u;
		if(l.v != r.v) return l.v < r.v;
		return l.w < r.w;
	});
	for(int i = 0, cx = 1e9, cy; i < N; i++){
		if(ed[i].u != cx) {
			cx = ed[i].u, cy = ed[i].v;
			if(ar[1][1]) printf("%d %d\n", ar[1][0], ar[1][1]), ar[1][0] = ed[i].z, ar[1][1] = 0;
			else if(ar[1][0]) printf("%d %d\n", ar[0][0], ar[1][0]), ar[0][0] = ed[i].z, ar[1][0] = 0;
			else if(ar[0][1]) printf("%d %d\n", ar[0][0], ar[0][1]), ar[0][0] = ed[i].z, ar[0][1] = 0;
			else if(ar[0][0]) ar[1][0] = ed[i].z;
			else ar[0][0] = ed[i].z;
		}
		else if(ed[i].v != cy) {
			cy = ed[i].v;
			if(ar[1][1]) printf("%d %d\n", ar[1][0], ar[1][1]), ar[1][0] = ed[i].z, ar[1][1] = 0;
			else if(ar[1][0]) ar[1][1] = ed[i].z;
			else if(ar[0][1]) printf("%d %d\n", ar[0][0], ar[0][1]), ar[0][0] = ed[i].z, ar[0][1] = 0;
			else if(ar[0][0]) ar[0][1] = ed[i].z;
			else ar[0][0] = ed[i].z;
		}
		else {
			if(ar[1][1]) printf("%d %d\n", ar[1][1], ed[i].z), ar[1][1] = 0;
			else if(ar[1][0]) printf("%d %d\n", ar[1][0], ed[i].z), ar[1][0] = 0;
			else if(ar[0][1]) printf("%d %d\n", ar[0][1], ed[i].z), ar[0][1] = 0;
			else if(ar[0][0]) printf("%d %d\n", ar[0][0], ed[i].z), ar[0][0] = 0;
			else ar[0][0] = ed[i].z;
		}
	}
	if(ar[1][1]) printf("%d %d\n", ar[1][0], ar[1][1]), ar[1][1] = 0, ar[1][0] = 0;
	if(ar[0][1]) printf("%d %d\n", ar[0][1], ar[0][0]), ar[0][1] = 0, ar[0][0] = 0;
	if(ar[1][0]) printf("%d %d\n", ar[0][0], ar[1][0]), ar[1][0] = 0;
}
