#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int fp[X], fn[X], N, M;
void ud(int aa[], int po, int va) {for(; po <= N + 1; po += -po & po) aa[po] += va; }
int qu(int aa[], int po) {int re = 0; for(; po; po -= -po & po) re += aa[po]; return re;}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0, u, v, w; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if(u == 1) {
			if(qu(fn, v) - qu(fn, v - 1)) ud(fn, v, -1);
			else ud(fp, v, 1);
			if(qu(fp, w + 1) - qu(fp, w)) ud(fp, w + 1, -1);
			else ud(fn, w + 1, 1);
		}
		if(u == 2) printf("%d %d\n", qu(fp, v) - qu(fn, v), qu(fp, w) - qu(fn, w));
		if(u == 3) printf("%d %d %d %d\n", qu(fp, v) - qu(fn, v), qu(fp, w) - qu(fn, w), qu(fp, w) - qu(fp, v), qu(fn, w) - qu(fn, v));
	}
	for(int i = 1; i <= N + 1; i++) cout << qu(fp, i) << ' '; cout << endl;
	for(int i = 1; i <= N + 1; i++) cout << qu(fn, i) << ' ';
}
/*
10 10
1 2 5
2 1 10
3 1 10
1 4 5
2 1 10
3 3 6
1 8 8
3 5 8
1 5 10
2 5 6
*/
