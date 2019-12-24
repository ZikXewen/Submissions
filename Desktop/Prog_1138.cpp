#include<cstdio>
#include<algorithm>
#include<set>
#define MXN 100005
#define MXL 1000000
//#define ii pair<int,int>
using namespace std;
int N,K,S,X[MXN],A[MXN],st[MXL],l,r,x,val,X2[MXN],J;
void ud(int s,int e,int idx){
	if(s==e){
		st[idx]=val;
		return;
	}
	int m=(s+e)>>1;
	if(x<=m) ud(s,m,idx<<1);
	else ud(m+1,e,idx<<1|1);
	st[idx]=max(st[idx<<1],st[idx<<1|1]);
}
int qr(int s,int e,int idx){
	if(r<s||l>e) return 0;
	if(s>=l&&e<=r) return st[idx];
	int m=(s+e)>>1;
	return max(qr(s,m,idx<<1),qr(m+1,e,idx<<1|1));
}
void del(){
	for(int i=1;i<=N;i++) if(X2[i]!=X2[J]) X2[++J]=X2[i]; J++;
}
int lb(int idx){
	return lower_bound(X2,X2+J,idx)-X2+1;
}
int ub(int idx){
	return upper_bound(X2,X2+J,idx)-X2;
}
int main(){
	scanf("%d%d%d",&N,&K,&S); X2[0]=S;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&X[i],&A[i]);
		X2[i]=X[i];
	}
	sort(X2,X2+N+1); del();
	//for(int i=0;i<J;i++) printf("%d ",X2[i]); printf("\n");
	for(int i=N;i>0;i--){
		x=lb(X[i]); l=lb(X[i]-K); r=ub(X[i]+K);
	//	printf("%d %d %d %d\n",X[i],x,l,r);
		val=qr(1,J,1)+A[i];
		ud(1,J,1);
	}
	x=lb(S); l=lb(S-K); r=ub(S+K);
	printf("%d",qr(1,J,1));
}
