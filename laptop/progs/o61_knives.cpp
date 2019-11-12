#include<cstdio>
#include<algorithm>
#define MXN 1000005
#define MXL 4000005
using namespace std;
int N,L,Q,dif,a,b,st[MXL],mx[MXL],mn[MXL],v[MXN],mk[MXL];
char c;
void ud(int s,int e,int idx){
	if(s==e) {st[idx]=mx[idx]=mn[idx]+=dif; return;}
	int m=(s+e)>>1;
	if(a<=m) ud(s,m,idx<<1);
	else ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
	mx[idx]=max(mx[idx<<1],mx[idx<<1|1]);
	mn[idx]=min(mn[idx<<1],mn[idx<<1|1]);
}
void flip(int s,int e,int idx){
	if(s==e) {if(mk[idx]!=2) mk[idx]=2; else mk[idx]=0;return;}
	int m=(s+e)>>1;
	if(a<=m) flip(s,m,idx<<1);
	else flip(m+1,e,idx<<1|1);
	if(mk[idx<<1]==2&&mk[idx<<1|1]==2) mk[idx]=2;
	else if(mk[idx<<1]||mk[idx<<1|1]) mk[idx]=1;
}
int qr2(int s,int e,int idx){
	if(mn[idx]+a>=L&&(mx[idx]!=0||s==e)) return st[idx]+(a-L)*(e-s+1);
	if(mx[idx]+a<L) return st[idx]+a*(e-s+1);
	int m=(s+e)>>1;
	return qr2(s,m,idx<<1)+qr2(m+1,e,idx<<1|1);
}
int qr(int s,int e,int idx){
	if(mk[idx]==2) return L*(e-s+1)-qr2(s,e,idx);
	if(mn[idx]+a>L&&!mk[idx]) return st[idx]+(a-L)*(e-s+1);
	if(mx[idx]+a<=L&&!mk[idx]) return st[idx]+a*(e-s+1);
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%d%d%d",&N,&L,&Q);
	while(Q--){
		scanf(" %c %d",&c,&a);
		if(c=='s'){ a++;
			scanf("%d",&b);
			if(v[a]<b) dif=L-b;
			else dif=-b;
			v[a]+=dif;
			ud(1,N,1);
			//printf("%d %d\n",a,dif);
		}
		if(c=='q') printf("%d\n",qr(1,N,1));
		if(c=='f') {a++; flip(1,N,1);}
	}
	//for(int i=0;i<N<<1;i++) printf("%d ",mk[i]);
}
/*
2 4 10
q 1
f 1
s 1 2
q 2
q 3
f 1
f 0
q 0
q 2
*/
