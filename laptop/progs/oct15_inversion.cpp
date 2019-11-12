	#include <bits/stdc++.h>
	using namespace std;
	const int X = 1e6 + 10;
	int N;
	long long an, ve[X], ar[X], fw[X];
	stack<int> st;
	bool comp(int u, int v) { return ve[u] > ve[v]; }
	void ud(int u) { for(; u <= N + 5; u += -u & u) fw[u]++; }
	int qe(int u) { int ret = 0; for(; u; u -= -u & u) ret += fw[u]; return ret;}
	int main(){
		scanf("%d", &N);
		iota(ar, ar + N + 1, 0);
		for(int i = 1; i <= N; i++) scanf("%d", &ve[i]);
		sort(ar + 1, ar + N + 1, comp);
		for(int i = 1, pv = -1; i <= N; i++){
			st.emplace(ar[i]);
			if(ve[ar[i]] != pv){
				pv = ve[ar[i]];
				while(!st.empty()) ud(st.top()), st.pop();
			} 
			an += qe(ar[i]);
		}
		printf("%lld", an);
	}
/*
5
10
40
30
50
20
*/
