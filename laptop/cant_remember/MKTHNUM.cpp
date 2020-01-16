#include <bits/stdc++.h>
#define MXN int(1e5+5)
using namespace std;
class tr{public:
	int w;
	tr *l,*r;
	tr(){w=0,l=r=this;}
};
tr* ver[MXN]={new tr()};
int N,M,v[MXN],ct,mp[MXN],rv[MXN];
bool comp(int L,int R){return v[L]<v[R];}
void ud(tr* cr,tr pr,int x,int s,int e){
	if(s==e) {cr->w=pr.w+1; return;}
	int m=(s+e)>>1;
	if(x<=m){
		cr->l=new tr();
		cr->r=pr.r;
		ud(cr->l,*(pr.l),x,s,m);
	} else {
		cr->r = new tr();
		cr->l=pr.l;
		ud(cr->r,*(pr.r),x,m+1,e);
	}
	cr->w=cr->l->w+cr->r->w;
}
int gt(tr cr,int l,int r, int s,int e){
	if(s>r||e<l) return 0;
	if(l<=s&&r>=e) return cr.w;
	int m=(s+e)>>1;
	return gt(*(cr.l),l,r,s,m)+gt(*(cr.r),l,r,m+1,e);
}
int que(int a,int b,int x){
	int s=1,e=N;
	while(s<e){
		int m=(s+e)>>1;
		if(gt(*ver[m],a,b,1,N)>=x) e=m;
		else s=m+1;
	}
	return s;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) {scanf("%d",&v[i]); mp[i]=i; ver[i]=new tr();} 
	sort(mp+1,mp+N+1,comp);
	for(int i=1;i<=N;i++) rv[i]=v[mp[i]];
	for(int i=1;i<=N;i++) ud(ver[i],*ver[i-1],mp[i],1,N);
	for(int i=0,a,b,c;i<M;i++) {
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",rv[que(a,b,c)]); // find ver k that gt(a,b) = c
	}
}
