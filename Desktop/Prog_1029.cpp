#include<cstdio>
#include<algorithm>
#define MXN 200010
using namespace std;
int N,M,Q,A,B,v[MXN],q;
void ud(int idx){
	for(;idx<=N;idx+=-idx&idx) v[idx]++;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=v[idx];
	return ret;
}
int main(){
	scanf("%d%d%d",&N,&M,&Q); M<<=1;
	for(int i=0;i<M;i++) {scanf("%d%d",&A,&B); ud(A);ud(B+1);}
	for(int i=0;i<M;i++) printf("%d ",v[i]);
	while(Q--){
		scanf("%d",&q);
		printf("%d\n",qr(q));
	}
}
/*
10 3 2
2 5
6 3
6 1
5
10
*/
