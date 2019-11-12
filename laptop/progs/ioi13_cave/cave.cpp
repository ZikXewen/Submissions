#include <bits/stdc++.h>
#include "graderlib.c"
using namespace std;

void exploreCave(int N){
	int st[N] = {}, nw[N] = {}, ga[N] = {}, ct = 0;
	vector<int> lf(N);
	iota(lf.begin(), lf.end(), 0);
	for(int i = 0; i < N; i++) {
		int l = 0, r = lf.size() - 1;
		bool op = (tryCombination(st) == i);
		while(l < r) {
			int m = (l + r) >> 1;
			copy(st, st + N, nw);
			for(int j = l; j <= m; j++) nw[lf[j]] = !st[lf[j]];
			if((tryCombination(nw) == i) != op) r = m;
			else l = m + 1;
		}
		st[lf[l]] = op;
		ga[lf[l]] = i; 
		lf.erase(lf.begin() + l);
	}
	answer(st, ga);
}
/* 
15
1 1 1 1 1 1 1 1 0 0 0 0 0 1 1
10 4 7 2 9 3 1 5 6 11 8 0 13 14 12
*/
