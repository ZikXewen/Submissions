#include<cstdio>
#define MXN 200005
using namespace std;
int N,M,A,B,C,D,ft[MXN];
void ud(int idx,int x){
	for(;idx<=N;idx+=-idx&idx) ft[idx]+=x;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int main(){
	scanf("%d%d",&N,&M);
	while(M--){
		scanf("%d%d",&A,&B);
		if(A==1){
			scanf("%d%d",&C,&D);
			ud(B,D); ud(C+1,-D);
		}
		else printf("%d\n",qr(B));
	}
}
