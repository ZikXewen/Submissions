#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define MXN 100005
#define MXR 300005
#define MXL 1500005
using namespace std;
bool ck[MXL];
int st[MXL],a,b,N,L,H,A,sz;
double gd[MXR],x[MXN];
vector<int> q[MXN];
map<double,int> m;
void del(){
	int j=0;
	for(int i=1;i<sz;i++) if(gd[i]!=gd[j]) gd[++j]=gd[i];
	sz=j+1;
}
double gt(int x,int y){
	return L+double(x*H)/y;
}
void ud(int s,int e,int idx,int val){
	if(ck[idx]){
		st[idx]=0;
		if(s!=e) ck[idx<<1]=ck[idx<<1|1]=true;
		ck[idx]=false;
	}
	if(e<val||s>val) return;
	if(s==e){
		st[idx]++; return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1,val);
	ud(m+1,e,idx<<1|1,val);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
int qr(int s,int e,int idx,int val){
	if(val==0) return 0;
	if(ck[idx]){
		st[idx]=0;
		if(s!=e) ck[idx<<1]=ck[idx<<1|1]=true;
		ck[idx]=false;
	}
	if(s>val) return 0;
	if(e<=val) return st[idx];
	int m=(s+e)>>1;
	return qr(s,m,idx<<1,val)+qr(m+1,e,idx<<1|1,val);
}
void cl(int s,int e,int idx,int val){
	if(s>e) return;
	if(ck[idx]){
		st[idx]=0;
		if(s!=e) ck[idx<<1]=ck[idx<<1|1]=true;
		ck[idx]=false;
	}
	if(e<val) return;
	if(s>=val){
		st[idx]=0;
		if(s!=e) ck[idx<<1]=ck[idx<<1|1]=true;
		return;
	}
	int m=(s+e)>>1;
	cl(s,m,idx<<1,val);
	cl(m+1,e,idx<<1|1,val);
	st[idx]=st[idx<<1]+st[idx<<1|1];
}
int main(){
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%d",&A); q[i].resize(A);
		while(A--){
			scanf("%d",&q[i][A]);
			gd[sz++]=q[i][A];
		}
		scanf("%d%d",&a,&b);
		gd[sz++]=x[i]=gt(a,b);
	}
	sort(gd,gd+sz); del(); //printf("%d\n",sz);
	for(int i=0;i<sz;i++) m[gd[i]]=i+1;
	for(int i=0;i<N;i++){
		//printf("%.0lf %d\n",x[i],m[x[i]]);
		for(int j:q[i]) ud(1,sz+1,1,m[j]);
		printf("%d\n",qr(1,sz+1,1,m[x[i]]-1));
		cl(1,sz+1,1,m[x[i]]);
		//for(int i=1;i<=sz<<1;i++) printf("%d ",st[i]); printf("\n");
		//for(int i=1;i<=sz<<1;i++) printf("%d ",ck[i]);
	}
}
/*
3 4 1
2 2 3 0 1
0 -1 1
1 5 1 1
*/
