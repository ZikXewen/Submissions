#include<bits/stdc++.h>
using namespace std;
class ii{public: int u,v;};
bool lft(const ii &L,const ii &R){return L.u<R.u;};
vector<ii> h;
vector<int> v;
int L,N,M;
void inp(){
	scanf("%d%d%d",&L,&N,&M);
	h.resize(N); v.resize(M+2);
	for(int i=0;i<N;i++) scanf("%d%d",&h[i].u,&h[i].v);
	for(int i=0;i<M;i++) scanf("%d",&v[i]);
	v[M]=0;v[M+1]=L;
}
void pre(){
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++) h[i].u=*lower_bound(v.begin(),v.end(),h[i].u), h[i].v=*(upper_bound(v.begin(),v.end(),h[i].v)-1);
	//sort(h.begin(),h.end(),lft);
}
void algo(){
	int cur=0,run=0,cnt=0;
	while(cur<L){
		int nxt=cur;
		while(h[run].u<=cur) nxt=max(nxt,h[run++].v);
		cur=nxt; cnt++;
	}
	printf("%d",(cnt<<1)-1);
}
int main(){
	inp();
	pre();
	algo();
}
