#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int X = 1e5 + 5;
int N, M, ar[X], pq[X][2], sr[X], l[X], r[X], an[X];
lint ft[X], sz[X];
double nq[X], cr;
bool ru;
stack<int> qu[X];
void ud(int x, int va) { for(; x <= N; x += -x & x) ft[x] += va, sz[x]++; }
lint gt(lint aa[], int x) { lint re = 0; for(; x; x -= -x & x) re += aa[x]; return re; }
int main(){
	freopen("in", "r", stdin); freopen("out", "w", stdout);
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d", ar + i + 1);
	for(int i = 0; i < M; i++) scanf("%d %d %lf", pq[i], pq[i] + 1, nq + i);
	iota(sr, sr + N, 1); fill_n(r, M, N - 1);
	sort(sr, sr + N, [](int L, int R){ return ar[L] > ar[R]; });
	do{
		ru = 0; memset(ft, 0, sizeof ft); memset(sz, 0, sizeof sz);
		for(int i = 0; i < M; i++) if(l[i] < r[i]) qu[(l[i] + r[i] + 1) >> 1].emplace(i);
		for(int i = 0; i < N; i++){
			ud(sr[i], ar[sr[i]]);
			while(qu[i].size()){	
				ru = 1;
				int x = qu[i].top(); qu[i].pop();
				lint va = gt(ft, pq[x][1]) - gt(ft, pq[x][0] - 1), si = gt(sz, pq[x][1]) - gt(sz, pq[x][0] - 1);
				if(!si) {r[x] = i - 1; continue;}
				else cr = (double) va / si;
				if(cr < nq[x]) r[x] = i - 1;
				else l[x] = i, an[x] = si;
			}
		}
	} while(ru);
	for(int i = 0; i < M; i++) printf("%d\n", an[i] ? pq[i][1] - pq[i][0] + 1 - an[i] : -1);
}
