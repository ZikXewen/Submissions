#include <bits/stdc++.h>
#define getchar_unlocked getchar
#define fputs_unlocked fputs
using namespace std;
struct node{
	node *cd[2] = {}, *pa;
	bool mk;
	int dir(){ // -1 when is root or is path parent
		if ((!pa) or !(pa -> cd[0] == this or pa -> cd[1] == this)) return -1;
		return pa -> cd[1] == this;
	}
	void ps(){ 
		if(mk){
			swap(cd[0], cd[1]);
			if(cd[0]) cd[0] -> mk ^= 1;
			if(cd[1]) cd[1] -> mk ^= 1;
			mk = 0;
		}
	}
	void rot() { 
		node *y = pa, *z = pa -> pa;
		int dx = dir(), dy = y -> dir();
		y -> add(dx, cd[!dx]);
		add(!dx, y);
		if(~dy) z -> add(dy, this);
		pa = z;
	}
	void spy() { 
		for(; ~dir(); rot()) {
			if(~(pa -> dir())) pa -> pa -> ps();
			pa -> ps(), ps();
			if(~(pa -> dir())) (dir() == pa -> dir()? pa : this) -> rot();
		}
	}
	void add(bool sd, node *nw){ 
		if(nw) nw -> pa = this;
		cd[sd] = nw;
	}
	void ac(){
		spy();
		for(node *t = this; t -> pa; t = t -> pa)
			t -> pa -> spy(), t -> pa -> cd[1] = t; 
		spy();
		cd[1] = nullptr;
	}
	void mkr(){ac(); mk ^= 1; ps();}
	node* rt(){
		ac(); node* t = this;
		for(; t -> cd[0]; t = t -> cd[0], t -> ps());
		return t;
	}
	node() = default;
} *tr[100005];
void link(node *u, node *v){
	u -> mkr();
	u -> pa = v;
}
void cut(node *u, node *v){
	u -> mkr(); v -> ac();
	v -> cd[0] = u -> pa = nullptr;
}
bool que(node *u, node *v){return u -> rt() == v -> rt();}
inline int fint(){
	int ret = 0;
	char c = 0;
	while(c < '0' or c > '9') c = getchar_unlocked();
	while(c >= '0' and c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', c = getchar_unlocked();
	return ret;
}
inline char fchr(){
	char c = 0;
	while(c <= ' ') c = getchar_unlocked();
	return c;
}
int main(){
	int N = fint(), M = fint();
	for(int i = 1; i <= N; ++i) tr[i] = new node();
	while(M--){
		char str = fchr(); 
		int u = fint(), v = fint();
		if(str == 'a') link(tr[u], tr[v]);
		else if(str == 'r') cut(tr[u], tr[v]);
		else fputs_unlocked(que(tr[u], tr[v])? "YES\n" : "NO\n", stdout);
	}
}