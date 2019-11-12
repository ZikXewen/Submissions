#include<cstdio>
#include<deque>
#define MXN 200005
#define MXL 1000005
using namespace std;
int N,ct,st[MXL],lz[MXL],p,q,a,m[MXN],v;
char c;
void ud(int s,int e,int idx){
	if(lz[idx]){
		st[idx]+=lz[idx];
		if(s!=e) {lz[idx<<1]+=lz[idx]; lz[idx<<1|1]+=lz[idx];}
		lz[idx]=0;
	}
	if(e<p||s>q) return;
	if(s>=p&&e<=q){
		st[idx]+=v;
		if(s!=e) {lz[idx<<1]+=v; lz[idx<<1|1]+=v;}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1);
	ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
int qr(int s,int e,int idx){
	if(lz[idx]){
		st[idx]+=lz[idx];
		if(s!=e) {lz[idx<<1]+=lz[idx]; lz[idx<<1|1]+=lz[idx];}
		lz[idx]=0;
	}
	if(e<p||s>q) return 0;
	if(s>=p&&e<=q) return st[idx];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf(" %c %d",&c,&a);
		if(c=='L') {
			p=1;
			m[a]=q=++ct; v=1;
			ud(1,N,1);
		}
		if(c=='R') {
			m[a]=p=q=v=++ct;
			ud(1,N,1);
		}
		if(c=='?') {
			p=q=m[a];
			int tem=qr(1,N,1);
			printf("%d\n",min(ct-tem,tem-1));
		}
	}
}
