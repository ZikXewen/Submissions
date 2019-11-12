#include<cstdio>
#include<algorithm>
#define MXN 200005
#define MXL 800005
using namespace std;
int L,N,st[MXL],st2[MXL],v[MXN],gd[MXN],l;
bool ck[MXL];
void bd(int s,int e,int idx){
	if(s==e){
		st[idx]=gd[s]-gd[s-1];
		return;
	}
	int m=(s+e)>>1;
	bd(s,m,idx<<1); bd(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];	
}
void ud(int s,int e,int idx){
	if(ck[idx]){
		swap(st[idx],st2[idx]); 
		if(s!=e){
			ck[idx<<1]=!ck[idx<<1];
			ck[idx<<1|1]=!ck[idx<<1|1];
		} 
		ck[idx]=false;
	}
	if(e<l) return;
	if(s>=l) {
		swap(st[idx],st2[idx]); 
		if(s!=e){
			ck[idx<<1]=!ck[idx<<1];
			ck[idx<<1|1]=!ck[idx<<1|1];
		}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1); ud(m+1,e,idx<<1|1);
	st[idx]=st[idx<<1]+st[idx<<1|1];
	st2[idx]=st2[idx<<1]+st2[idx<<1|1];
}
int main(){
	scanf("%d%d",&L,&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&v[i]);
		gd[i]=v[i];
	}
	gd[N+1]=L;
	sort(gd,gd+N+2);
	bd(1,++N,1);
	for(int i=1;i<N;i++){
		l=lower_bound(gd,gd+N,v[i])-gd+1;
		ud(1,N,1);
		printf("%d\n",st[1]);
	}
}
