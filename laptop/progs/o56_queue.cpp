#include<cstdio>
#define MXN 200005
#define MXL 100005
using namespace std;
int N,cmd,val,ft[MXL],m[MXL],ct,M[MXL];
void ud(int idx,int x){
	for(;idx<=MXL-1;idx+=-idx&idx) ft[idx]+=x;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int b_search(int s,int e){
	if(s>e){
		if(s==MXL) return 0;
		ud(s,-1);
		return s;
	}
	int m=(s+e)>>1;
	if(qr(m)>=1) return b_search(s,m-1);
	return b_search(m+1,e);
}
int main(){
	scanf("%d",&N); while(N--){ //printf("o");
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d",&val);
			m[++ct]=val; M[val]=ct;
			ud(m[ct],1);
		}
		else if(cmd==2) printf("%d\n",M[b_search(1,MXL-1)]);
		else {scanf("%d",&val); printf("%d\n",qr(m[val])-1);}
	}
}
