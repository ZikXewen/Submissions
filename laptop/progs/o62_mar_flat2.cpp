#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
vector<int> v[10 * X];
int h[X], pa[X], an[X], N, W;
int fd(int u){
	if(pa[u] < 0) return u;
	return pa[u] = fd(pa[u]);
}
int main(){
	memset(an, -1, sizeof an);
	memset(pa, -1, sizeof pa);
	scanf("%d %d", &N, &W);
	for(int i = 0; i < N; i++){
		scanf("%d", &h[i]);
		v[h[i]].emplace_back(i);
	}
	for(int i = 1e6; i; i--){
		for(int j: v[i]){
			if(j && h[j] <= h[j - 1]){
				int a = fd(j), b= fd(j - 1);
				if(a != b) pa[a] += pa[b], pa[b] = a;
			}
			if(j < N-1 && h[j] <= h[j + 1]){
				int a = fd(j), b = fd(j + 1);
				if(a != b) pa[a] += pa[b], pa[b] = a;
			}
		}
		for(int j: v[i]){
			int tem = -pa[fd(j)] - 1;
			if(an[tem] == -1) an[tem] = i;
		}
	}
	if(W == -10) for(int i = 1; i <= N; i++) printf("%d ", an[i]);
	else printf("%d", an[W]);
}
