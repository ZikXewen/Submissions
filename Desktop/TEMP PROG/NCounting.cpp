#include<iostream>
#include<algorithm>
#define MXN 20005
#define MXQ 400005
using namespace std;
class ii{
	public:int X,NO;
};
class iii{
	public:
	int S,E,K,NO,typ;
};
bool comp1(ii L, ii R){
	return L.X>R.X;
}
bool comp2(iii L,iii R){
	return L.K>R.K;
}
int N,Q,a,b,c,d,ct,ans[MXQ],ft[MXN];
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
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++) {scanf("%d",&v[i].X); v[i].NO=i+1;}
	sort(v,v+N,comp1);
	for(int i=0;i<2*Q;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		qs[i]={a,b,c-1,i,1};
		qs[i+1]={a,b,d,i++,-1};
	}
	sort(qs,qs+2*Q,comp2);
	for(int i=0;i<2*Q;i++){
		while(ct<N&&v[ct].X>qs[i].K) ud(v[ct++].NO);
		ans[qs[i].NO]+=(qr(qs[i].E)-qr(qs[i].S-1))*qs[i].typ;
	}
	for(int i=0;i<2*Q;i+=2) printf("%d ",ans[i]);
}
