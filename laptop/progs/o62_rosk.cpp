#include<bits/stdc++.h>
using namespace std;
class ii{public: int x,y;};
const int MXN =1e5+5;
const int INF = 2e9;
int N,M,hx,hy,ct;
vector<ii> v[2],h[2];
ii fp;
void inp(){
	int a,b;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) {scanf("%d%d",&a,&b); v[0].push_back({a,b});}
	for(int i=0;i<M;i++) {scanf("%d%d",&a,&b); v[1].push_back({a,b});}
}
int turn(ii x,ii y,ii z){
	return ((x.x-y.x)*(z.y-y.y))-((x.y-y.y)*(z.x-y.x));
}
bool comp(const ii &L,const ii &R){
	return turn({-INF,-INF},fp,L) < turn({-INF,-INF},fp,R);
}
void cohu(vector<ii> &x,vector<ii> &out){
	int mn=0;
	for(int i=0;i<x.size();i++) if(x[i].y<x[mn].y) mn=i;
	swap(x[mn],x[0]); fp=x[0];
	sort(x.begin()+1,x.end(),comp);
	vector<ii> nw={x[0]};
	for(int i=1;i<x.size()-1;i++) if(turn(nw.back(),x[i],x[i+1])) nw.emplace_back(x[i]);
	if(turn(nw.back(),x.back(),x[0])) nw.emplace_back(x.back());
	for(ii i:nw) cout << i.x << i.y << ' ';
	out={nw[0],nw[1]};
	for(int i=0;i<nw.size();i++){
		if(turn(out[out.size()-2],out.back(),nw[i])<0) out.pop_back();
		out.push_back(nw[i]);
	}
}
bool comp2(const ii &L,const ii &R){
	return L.y<R.y;
}
bool ins(ii pt,vector<ii> &sh,int half){
	
}
int main(){
	inp();
	cohu(v[0],h[0]); cohu(v[1],h[1]);
	hx=h[0].size()-1,hy=h[1].size()-1;
	for(int i=1;i<h[0].size();i++) if(h[0][i].y<h[0][i-1].y) hx=i-1;
	for(int i=1;i<h[1].size();i++) if(h[1][i].y<h[1][i-1].y) hy=i-1;
	for(ii i:h[0]) if(ins(i,h[1],hy)) ct++;
	for(ii i:h[1]) if(ins(i,h[0],hx)) ct++;
	cout << ct;
}
