#include<bits/stdc++.h>
using namespace std;
class tr{ public:
	int mx,ll,rr,sz;
	tr *l,*r;
	tr(){ mx=0,ll=0,rr=0,sz=1; l=NULL;r=NULL; }
	tr(int x){ mx=x,ll=x,rr=x,sz=x; l=NULL;r=NULL; }
};
const int MXN=1e5+5;
int N,M;
int v[MXN],u[MXN];
tr *ver[MXN];
bool comp(int L,int R){return v[L]>v[R];}
void inp(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) {scanf("%d",&v[i]); u[i]=i; ver[i]=new tr();}
	scanf("%d",&M);
	ver[N]=new tr();
}
void spl(tr *x,tr L,tr R){
	x->sz=L.sz+R.sz;
	x->ll=(L.sz==L.mx)? L.sz+R.ll : L.ll;
	x->rr=(R.sz==R.mx)? L.rr+R.sz : R.rr;
	x->mx=max(max(L.mx,R.mx),L.rr+R.ll);
}
void bd(tr *cr,int s,int e){
	if(s==e) return;
	int m=(s+e)>>1;
	cr->l=new tr();
	cr->r=new tr();
	bd(cr->l,s,m);
	bd(cr->r,m+1,e);
}
void ud(tr *pr,tr *cr,int x,int s,int e){
	if(s==e){*cr=tr(1); return;}
	int m=(s+e)>>1;
	if(x<=m){
		cr->l=new tr();
		cr->r=pr->r;
		ud(pr->l,cr->l,x,s,m);
	}else{
		cr->l=pr->l;
		cr->r=new tr();
		ud(pr->r,cr->r,x,m+1,e);
	}
	spl(cr,*(cr->l),*(cr->r));
}
tr gt(tr *cr,int a,int b,int s,int e){
	if(a>e||b<s||cr==NULL) return tr();
	if(a<=s&&b>=e) return *cr;
	int m=(s+e)>>1;
	tr ret=tr();
	spl(&ret,gt(cr->l,a,b,s,m),gt(cr->r,a,b,m+1,e));
	return ret;
}
void qr(){
	int l,r,h,s=0;
	scanf("%d%d%d",&l,&r,&h);
	for(int e=N;e>s;){
		int m=(s+e)>>1;
		if(gt(ver[m],l,r,0,N).mx>=h) e=m;
		else s=m+1;
	}
	printf("%d\n",v[u[s-1]]);
}
int main(){
	inp();
	sort(u,u+N,comp);
	bd(ver[0],0,N);
	for(int i=0;i<N;i++) ud(ver[i],ver[i+1],u[i]+1,0,N);
	while(M--) qr();
}