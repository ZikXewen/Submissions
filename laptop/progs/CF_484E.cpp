#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
class nd{ public:
	int mx,ll,rr,sz;
	nd *l,*r;
	nd(){mx=0,ll=0,rr=0,sz=1; l=NULL,r=NULL;}
	nd(int x){mx=x,ll=x,rr=x,sz=x; l=NULL,r=NULL;}
};
int N,M;
int h[MXN],srt[MXN];
nd *st[MXN];
bool comp(const int &_l,const int &_r){ return h[_l]>h[_r]; }
void inp(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) {scanf("%d",&h[i]); srt[i]=i;}
	scanf("%d",&M);
}
void bd(nd *cr,int s,int e){
	if(s==e) return;
	int m=(s+e)>>1;
	cr->l=new nd();
	cr->r=new nd();
	bd(cr->l,s,m);
	bd(cr->r,m+1,e);
}
void chn(nd *x, const nd L, const nd R){
	x->sz=L.sz+R.sz;
	if(L.sz==L.mx) x->ll=L.sz+R.ll;
	else x->ll=L.ll;
	if(R.sz==R.mx) x->rr=R.sz+L.rr;
	else x->rr=R.rr;
	x->mx=max(L.rr+R.ll,max(L.mx,R.mx));
}
void ud(nd *pv, nd *cr,int x,int s,int e){ 
	if(s>x||e<x) return;
	if(s==e) {
		*cr=nd(1);return;
	}
	int m=(s+e)>>1;
	if(x<=m){
		cr->l = new nd();
		cr->r = pv->r;
		ud(pv->l,cr->l,x,s,m);
	} else{
		cr->l = pv->l;
		cr->r = new nd();
		ud(pv->r,cr->r,x,m+1,e);
	}
	chn(cr,*(cr->l),*(cr->r));
}
nd gt(nd *cur,int x,int y,int s,int e){
	if(x>e||y<s||cur==NULL) return nd();
	if(x<=s&&y>=e) return *cur;
	int m=(s+e)>>1;
	nd ret= nd();
	chn(&ret,gt(cur->l,x,y,s,m),gt(cur->r,x,y,m+1,e));
	return ret;
}
void qr(){
	int _l,_r,_w,lw=0,hg=N,md;
	scanf("%d%d%d",&_l,&_r,&_w);
	while(hg>lw){
		md=(hg+lw)>>1; int I=gt(st[md],_l,_r,0,MXN).mx;
		if(I>=_w) hg=md;
		else  lw=md+1;
	}
	printf("%d\n",h[srt[lw-1]]);
}
int main(){
	inp();
	sort(srt,srt+N,comp);
	for(int i=0;i<=N;i++) st[i]=new nd();
	bd(st[0],0,MXN);
	for(int i=0;i<N;i++) ud(st[i],st[i+1],srt[i]+1,0,MXN);
	for(int i=0;i<M;i++) qr();
}
