#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
vector<ii> cr; int an;
int solution(vector<int> &A){
	for(int i = 0, j = 0; i < A.size(); ++i){
		bool fd = 0;
		for(ii i: A[i]) if(i.x == A[i]) i.y = i, fd = 1;
		if(fd) {an = max(an, i - j); continue;}
		if(cr.size() < 2) cr.emplace_back(A[i], i);
		else{
			if(cr[0].y < cr[1].y) swap(cr, cr + 1);
			j = cr[1].y,cr.pop_back();
		}
		an = max(an, i - j);
	}
	return an + 1;
}