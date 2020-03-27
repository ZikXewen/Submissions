#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
struct one{
	int sz, mn, mx;
	one *summ; vector<one*> clus;
	int high(int x){return x / (int)ceil(sqrt(sz));}
	int low(int x){return x % (int)ceil(sqrt(sz));}
	int gen(int u, int v){return u * ceil(sqrt(sz)) + v;}
	one(int _sz){
		sz = _sz; mn = mx = -1;
		if(_sz > 2) 
			{int no = ceil(sqrt(_sz)); summ = new one(no), clus.resize(no); for(auto &i: clus) i = new one(no);}
		else summ = 0, clus.clear();
	}
} *tr;
void ins(int x, one *u = tr){
	if(u -> mn == -1) {u -> mn = u -> mx = x; return;}
	if(x < u -> mn) swap(u -> mn, x);
	if(u -> sz > 2){
		if(u -> clus[u -> high(x)] -> mn == -1){
			ins(u -> high(x), u -> summ);
			u -> clus[u -> high(x)] -> mn = u -> clus[u -> high(x)] -> mx = u -> low(x);
		}
		else ins(u -> low(x), u -> clus[u -> high(x)]);
	}// can re-refer u -> clus[u -> high(x)]
	if(x > u -> mx) u -> mx = x;
}
bool mem(int x, one *u = tr){
	if(u -> sz < x) return 0;
	if(u -> mn == x || u -> mx == x) return 1;
	if(u -> sz == x) return 0;
	return mem(u -> low(x), u -> clus[u -> high(x)]);
}
int succ(int x, one *u = tr){
	if(u -> sz == 2) return (!x && u -> mx == 1)? 1 : -1;
	if(u -> mn != -1 && x < u -> mn) return u -> mn;
	int xclus = u -> clus[u -> high(x)] -> mx;
	if(xclus != -1 && u -> low(x) < xclus)
		return u -> gen(u -> high(x), succ(u -> low(x), u -> clus[u -> high(x)]));
	int sclus = succ(u -> high(x), u -> summ);
	if(sclus == -1) return -1;
	return u -> gen(sclus, u -> clus[sclus] -> mn);
}
int pred(int x, one *u = tr){
	if(u -> sz == 2) return (x == 1 && u -> mn == 0)? 0 : -1;
	if(u -> mx != -1 && x > u -> mx) return u -> mx;
	int nclus = u -> clus[u -> high(x)] -> mn;
	if(nclus != -1 && u -> low(x) > nclus)
		return u -> gen(u -> high(x), pred(u -> low(x), u -> clus[u -> high(x)]));
	int pclus = pred(u -> high(x), u -> summ);
	if(pclus == -1) return -1;
	return u -> gen(pclus, u -> clus[pclus] -> mx);
}
void del(int x, one *u = tr){
	if(u -> mx == u -> mn) {u -> mx = u -> mn = -1; return;}
	if(u -> sz == 2) {u -> mx = u -> mn = !x; return;}
	if(x == u -> mn){
		int fclus = u -> summ -> mn;
		u -> mn = x = u -> gen(fclus, u -> clus[fclus] -> mn);
	}
	del(u -> low(x), u -> clus[u -> high(x)]);
	if(u -> clus[u -> high(x)] -> mn == -1){
		del(u -> high(x), u -> summ);
		if(x == u -> mx){
			int xsumm = u -> summ -> mx;
			if(xsumm == -1) u -> mx = u -> mn;
			else u -> mx = u -> gen(xsumm, u -> clus[xsumm] -> mx);
		}
		return;
	}
	if(x == u -> mx) u -> mx = u -> gen(u -> high(x), u -> clus[u -> high(x)] -> mx);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M; cin >> N >> M; tr = new one(N);
	for(int i = 0, u, v; i < M; ++i){
		cin >> u;
		// 0 = insert, 1 = delete, 2 = min, 3 = max, 4 = pred, 5 = succ, 6 = exist
		switch(u){
			case 0: cin >> v; ins(v); break;
			case 1: cin >> v; del(v); break;
			case 2: cout << tr -> mn; break;
			case 3: cout << tr -> mx; break;
			case 4: cin >> v; cout << pred(v); break;
			case 5: cin >> v; cout << succ(v); break;
			case 6: cin >> v; cout << mem(v);
		}
	}
}