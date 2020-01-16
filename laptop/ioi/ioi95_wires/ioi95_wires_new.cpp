#include <bits/stdc++.h>
#include "wirelib.h"
#include "wirelib.cpp"
using namespace std;
const int X = 95;
int so[X];
void wi(int l, int r, bool cur, vector<int> ar){
	if(ar.empty()) return;
	if(l == r) {for(int i: ar) so[i] = l; return;}
	int m = (l + r) >> 1;
	vector<int> ll, rr;
	for(int i = l; i <= m; i++) cmd_C(i);
	for(int i: ar) 
		if(cmd_T(i) != cur) ll.emplace_back(i);
		else rr.emplace_back(i);
	wi(l, m, !cur, ll); wi(m + 1, r, cur, rr);
}
int main() {
	int N = wire_init();
	vector<int> st(N);
	iota(st.begin(), st.begin() + N, 1);
	wi(1, N, 0, st);
	cmd_D(so);
}
