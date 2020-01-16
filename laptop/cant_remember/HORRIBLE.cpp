#include<cstdio>
#include<cstring>
#define MXL 400005
using namespace std;
int T,N,C,cmd,p,q;
long long v,st[MXL],lz[MXL];
void ud(int s,int e,int idx){
	if(lz[idx]){
		st[idx]+=lz[idx]*(e-s+1);
		if(s!=e) {lz[idx<<1]+=lz[idx]; lz[idx<<1|1]+=lz[idx];}
		lz[idx]=0;
	}
	if(e<p||s>q) return;
	if(s>=p&&e<=q){
		st[idx]+=v*(e-s+1);
		if(s!=e) {lz[idx<<1]+=v; lz[idx<<1|1]+=v;}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1);
	ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
long long qr(int s,int e,int idx){
	if(lz[idx]){
		st[idx]+=lz[idx]*(e-s+1);
		if(s!=e) {lz[idx<<1]+=lz[idx]; lz[idx<<1|1]+=lz[idx];}
		lz[idx]=0;
	}
	if(e<p||s>q) return 0LL;
	if(s>=p&&e<=q) return st[idx];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%d",&T); while(T--){
		memset(st,0LL,sizeof st);
		memset(lz,0LL,sizeof lz);
		scanf("%d%d",&N,&C); while(C--){
			scanf("%d%d%d",&cmd,&p,&q);
			if(cmd) printf("%lld\n",qr(1,N,1));
			else{
				scanf("%lld",&v); ud(1,N,1);
			}
		}
	}
}
