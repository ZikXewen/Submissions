#include<cstdio>
#include<cstring>
#define MXL 1000000
using namespace std;
int N,C,l,r,cmd;
long long T,v,st[MXL],lz[MXL];
void ud(int s,int e,long long idx){
	if(lz[idx]){
		st[idx]+=lz[idx]*(e-s+1);
		if(s!=e) lz[idx<<1]+=lz[idx<<1|1]+=lz[idx];
		lz[idx]=0;
	}
	if(r<s||l>e||s>e) return;
	if(s>=l&&e<=r){
		st[idx]+=v*(e-s+1);
		if(s!=e) lz[idx<<1]+=lz[idx<<1|1]+=v;
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1);
	ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
long long qr(int s,int e,long long idx){
	if(lz[idx]){
		st[idx]+=lz[idx]*(e-s+1);
		if(s!=e) lz[idx<<1]+=lz[idx<<1|1]+=lz[idx];
		lz[idx]=0;
	}
	if(r<s||l>e||s>e) return 0;
	if(s>=l&&e<=r) return st[idx];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%lld",&T); while(T--){
		memset(st,0,sizeof st);
		memset(lz,0,sizeof lz);
		scanf("%d%d",&N,&C);
		while(C--){
			scanf("%d%d%d",&cmd,&l,&r);
			if(cmd) printf("%lld\n",qr(1,N,1));
			else{
				scanf("%lld",&v);
				ud(1,N,1);
			}
		}
	}
}
