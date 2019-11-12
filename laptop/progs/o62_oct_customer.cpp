#include <bits/stdc++.h>
using namespace std;
const int X = 3e5 + 5;
int N, M, Q, ar[X], te[X];
vector<int> ve[X];
int main(){
	scanf("%d %d %d", &N, &M, &Q);
if(N <= 1e3 && M <= 1e3 && Q <= 1e3){
	for(int i = 1, T, u; i <= M; i++) {scanf("%d", &T); while(T--) scanf("%d", &u), ve[u].emplace_back(i);}
	while(Q--){
		int t, u, v, an = 0; scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &u, &v);
			ar[u] = v;
		} else {
			scanf("%d", &u);
			for(int i: ve[u]) an += ar[i];
			printf("%d\n", an);
		}
	}
}
else {
	for(int i = 1, T, u; i <= M; i++) {scanf("%d", &T); while(T--) scanf("%d", &u), ve[i].emplace_back(u);}
	while(Q--){	
		int t, u, v; scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &u, &v);
			for(int i: ve[u]) ar[i] += v - te[u];
			te[u] = v;
		} else {
			scanf("%d", &u);
			printf("%d\n", ar[u]);
		}
	}
}
}
