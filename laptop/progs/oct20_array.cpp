#include<cstdio>
#include<set>
#include<algorithm>
#define MXQ 100005
using namespace std;
class que{
	public:
	bool typ;
	int l,r,v;
};
int N,Q,sz,gd[MXQ<<1],l,r,v;
long long st[MXQ<<3],lz[MXQ<<3];
bool ck[MXQ<<3];
que q[MXQ];
void del(){
	int j=0;
	for(int i=0;i<(Q<<1);i++) if(gd[i]!=gd[j]) gd[++j]=gd[i];
	sz=j+1;
}
int fd(int x){
	return lower_bound(gd,gd+sz,x)-gd+1;
}
void ud(int s,int e,int idx){
	if(ck[idx]){
		st[idx]=lz[idx] * (gd[e-1]-gd[s-1]+1LL);
		if(s!=e){
			ck[idx<<1]=ck[idx<<1|1]=true;
			lz[idx<<1]=lz[idx<<1|1]=lz[idx];
		}
		ck[idx]=false;
	}
	if(s>r||e<l) return;
	if(s>=l&&e<=r){
		st[idx]=(gd[e-1]-gd[s-1]+1LL)*v;// printf("%d %d %lld\n",gd[e]-1,gd[s-1],st[idx]);
		if(s!=e){
			ck[idx<<1]=ck[idx<<1|1]=true;
			lz[idx<<1]=lz[idx<<1|1]=1LL*v;
		}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1); ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
long long qr(int s,int e,int idx){
	if(ck[idx]){
		st[idx]=lz[idx] * (gd[e-1]-gd[s-1]+1LL);
		if(s!=e){
			ck[idx<<1]=ck[idx<<1|1]=true;
			lz[idx<<1]=lz[idx<<1|1]=lz[idx];
		}
		ck[idx]=false;
	}
	if(s>r||e<l) return 0LL;
	if(s>=l&&e<=r) return st[idx];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0;i<Q;i++){
		scanf("%d%d%d",&q[i].typ,&q[i].l,&q[i].r);
		if(!q[i].typ) scanf("%d",&q[i].v);
		gd[i<<1]=q[i].l;
		gd[i<<1|1]=--q[i].r;
	}
	sort(gd,gd+(Q<<1)); del();
	for(int i=0;i<sz;i++) printf("%d ",gd[i]);
	for(int i=0;i<Q;i++){
		l=fd(q[i].l); r=fd(q[i].r); v=q[i].v; printf("\n%d %d %d\n",l,r,v);
		if(q[i].typ) printf("%lld\n",qr(1,sz,1));
		else ud(1,sz,1);
	}
}
/*
9
7
0 0 4 1
1 1 3
0 1 2 2
0 3 8 3
1 1 4
0 6 7 4
1 0 9
*/
