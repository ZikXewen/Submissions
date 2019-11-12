#include <cstdio>
#include <vector>
#include <algorithm>
#define MXL 800005
using namespace std;
class ii{
public: int mx,no,l,r;
};
int N,M,u,v,w,lz[MXL];
ii st[MXL];
void bd(int s,int e,int idx){
	if(s==e) {st[idx].no=1; return;}
	int m=(s+e)>>1;
	bd(s,m,idx<<1); bd(m+1,e,idx<<1|1);
	st[idx].no=1;
}
void ud(int s,int e,int idx){
	if(lz[idx]){
		st[idx].mx+=lz[idx];
		st[idx].l+=lz[idx];
		st[idx].r+=lz[idx];
		if(s!=e){
			lz[idx<<1]+=lz[idx];
			lz[idx<<1|1]+=lz[idx];
		}
		lz[idx]=0;
	}
	if(s>v||e<u) return;
	if(s>=u&&e<=v){
		st[idx].mx+=w;
		st[idx].l+=w;
		st[idx].r+=w;
		if(s!=e){
			lz[idx<<1]+=w;
			lz[idx<<1|1]+=w;
		}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1); ud(m+1,e,idx<<1|1);
	st[idx].l=st[idx<<1].l;
	st[idx].r=st[idx<<1|1].r;
	st[idx].mx=max(st[idx<<1].mx,st[idx<<1|1].mx);
	if(st[idx<<1].mx==st[idx<<1|1].mx){ 
		st[idx].no=st[idx<<1].no+st[idx<<1|1].no;
		if(st[idx<<1].r==st[idx<<1|1].l&&st[idx<<1|1].l==st[idx<<1].mx) st[idx].no--;
		return;
	}
	if(st[idx<<1].mx>st[idx<<1|1].mx) st[idx].no=st[idx<<1].no;
	else st[idx].no=st[idx<<1|1].no;
}
int main(){
	scanf("%d%d",&N,&M);
	bd(1,N,1);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		ud(1,N,1);
		printf("%d %d\n",st[1].mx,st[1].no);
	}
}
