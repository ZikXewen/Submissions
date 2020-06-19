#include <bits/stdc++.h>
#include "castle.cpp"
#define ii pair<int, int>
using namespace std;

const int X = 1e5 + 5;
int N, M, Q, Y, p[X], pa[X];
vector<int> A, B;
vector<ii> ed;
stack<ii> stk;
void change(int u, int v){
	stk.emplace(u, p[u]);
	p[u] = v;
}
void rollback(){
	while(!stk.empty()){
		auto [u, v] = stk.top(); stk.pop();
		p[u] = v;
	}
}
int main() {
	castle_init(N, M, Q, Y); 
	for(int i = 1; i < N; ++i) p[i] = (i - 1) >> 1;
	castle_read_map(A, B);
	for(int i = 0; i < M; ++i) ed.emplace_back(min(A[i], B[i]), max(A[i], B[i]));
	while (Q--) {
		int T, X, Y;
		castle_read_event(T, X, Y);
		if(T == 1){
			auto [x, y] = ed[X];
			if(X >= N - 1) ed[X] = ii(0, 0);
			else p[y] = y;
		} else {
			int x = X, y = Y, fd = 0;
			while(p[x] != x) x = p[x]; //log n
			while(p[y] != y) y = p[y]; //log n
			if(x == y) {castle_answer(1); continue;}
			for(int i = N - 1; i < M; ++i){ //10
				auto [u, v] = ed[i];
				if(!u and !v) continue;
				while(p[u] != u) u = p[u];
				while(p[v] != v) v = p[v];
				if(u != v) change(u, v);
			}
			while(p[x] != x) x = p[x];
			while(p[y] != y) y = p[y];
			castle_answer(x == y);
			rollback();
		}
	}

}
/*

7 8 7 1
0 1
0 2
1 3
1 4
2 5
2 6
1 5
4 0
1 4 0
2 2 5
1 0 0
2 3 6
1 7 0
2 5 2
2 3 5
*/