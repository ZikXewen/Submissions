#include<iostream>
#include<algorithm>
#define MXN 30005
#define MXQ 200005
using namespace std;
class ii{
	public:int X,NO;
};
class iii{
	public:int S,E,K,NO;
};
bool comp1(ii L, ii R){
	return L.X>R.X;
}
bool comp2(iii L,iii R){
	return L.K>R.K;
}
int N,Q,a,b,c,ct,ans[MXQ],ft[MXN];
ii v[MXN];
iii qs[MXQ];
void ud(int idx){
	for(;idx<=N;idx+=-idx&idx) ft[idx]++;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) {scanf("%d",&v[i].X); v[i].NO=i+1;}
	sort(v,v+N,comp1);
	scanf("%d",&Q);
	for(int i=0;i<Q;i++) {scanf("%d%d%d",&qs[i].S,&qs[i].E,&qs[i].K); qs[i].NO=i;}
	sort(qs,qs+Q,comp2);
	for(int i=0;i<Q;i++){
		while(ct<N&&v[ct].X>qs[i].K) ud(v[ct++].NO);
		ans[qs[i].NO]=qr(qs[i].E)-qr(qs[i].S-1);
	}
	for(int i=0;i<Q;i++) printf("%d\n",ans[i]);
}
