#include "paint.h"
#include <bits/stdc++.h>
using namespace std;
int minimumInstructions( int N, int M, int K, vector<int> C, vector<int> A, vector<vector<int>> B) {
	vector<vector<int>> f(K), ff(N);
	vector<int> mem(M), an;
	for(int i = 0; i < M; ++i) for(int j: B[i]) f[j].emplace_back(i);
	for(int i = 0; i < N; ++i) for(int j: f[C[i]]) ff[i].emplace_back(((j - i) % M + M) % M);
	for(int i = 0, ct = 0; i < N; ++i) {
		if(i >= M) for(int j: ff[i - M]) if(--mem[j] == M - 1) --ct;
		for(int j: ff[i]) if(++mem[j] == M) ++ct;
		if(ct) an.emplace_back(i);
	}
	if(an.empty() or upper_bound(an.begin(), an.end(), M - 1) == an.begin()) return -1;
	for(int i = -1, ct = 1, tem;; i = tem, ++ct){
		tem = *(upper_bound(an.begin(), an.end(), i + M) - 1);
		if(tem == N - 1) return ct;
		if(tem == i) return -1;
	}
}
/*
8 3 5
3 3 1 3 4 4 2 2
3 0 1 2
2 2 3
2 3 4

5 4 4
1 0 1 2 2
2 0 1
1 1
1 2
1 3
*/