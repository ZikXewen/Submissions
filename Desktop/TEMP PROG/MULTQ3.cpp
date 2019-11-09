#include<cstdio>
#define MXL 1000000
using namespace std;
int N,T,Q,l,r,lz[MXL],st[MXL][3];
void bd(int s, int e, int idx){
	if(s==e){
		st[idx][0]=1;
		return;
	}
	int m=(s+e)/2;
	bd(s,m,idx<<1);
	bd(m+1,e,idx<<1|1);
	st[idx][0]=st[idx<<1][0]+st[idx<<1|1][0];
}
void inc(int tim, int idx){
	tim%=3; if(!tim) return;
	while(tim--){
		int temp = st[idx][2];
		st[idx][2]=st[idx][1];
		st[idx][1]=st[idx][0];
		st[idx][0]=temp;
	}
}
void ud(int s, int e, int idx){
	if(lz[idx]){
		inc(lz[idx],idx);
		if(s<e){
			lz[idx<<1] += lz[idx]; lz[idx<<1|1] += lz[idx];
		}
		lz[idx]=0;
	}
	if(e<l||s>r||s>e) return;
	if(s>=l&&e<=r){
		inc(1,idx);
		if(s!=e){
			lz[idx<<1]++; lz[idx<<1|1]++;
		}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1); ud(m+1,e,idx<<1|1);
	st[idx][0]=st[idx<<1][0]+st[idx<<1|1][0];
	st[idx][1]=st[idx<<1][1]+st[idx<<1|1][1];
	st[idx][2]=st[idx<<1][2]+st[idx<<1|1][2];
}
int qr(int s,int e,int idx){
	if(lz[idx]){
		inc(lz[idx],idx);
		if(s<e){
			lz[idx<<1] += lz[idx]; lz[idx<<1|1] += lz[idx];
		}
		lz[idx]=0;
	}
	if(e<l||s>r||s>e) return 0;
	if(s>=l&&e<=r) return st[idx][0];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1)+qr(m+1,e,idx<<1|1);
}
int main(){
	scanf("%d%d",&N,&Q); N++;
	bd(1,N,1);
	while(Q--){
		scanf("%d%d%d",&T,&l,&r);
		l++; r++;
		if(T) printf("%d\n",qr(1,N,1));
		else ud(1,N,1);
	}
}
