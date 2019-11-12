#include<cstdio>
#include<algorithm>
#define MXM 100005
#define MXL 200005
#define ii pair<int,int>
using namespace std;
int N,M,gd[MXL],ft[MXL],q[MXM],ct,SZ;
ii v[MXM];
void ud(int idx,int x){
	for(;idx<=MXL;idx+=-idx&idx) ft[idx]+=x;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int gt(int x){
	return lower_bound(gd,gd+SZ,x)-gd+1;
}
void del(){
	int j=0;
	for(int i=0;i<SZ;i++) if(gd[i]!=gd[j]) gd[++j]=gd[i];
	SZ=j+1;
}
int main(){
	scanf("%d%d",&N,&M); N<<=1;
	for(int i=0;i<N;i+=2){
		scanf("%d%d",&gd[i],&gd[i+1]);
		v[i]={gd[i]+1,1}; v[i+1]={gd[i+1],-1};
	}
	for(int i=0;i<M;i++){
		scanf("%d",&q[i]);
		gd[N+i]=q[i];
	}
	SZ=N+M;
	sort(gd,gd+SZ); del();
	//for(int i=0;i<N;i++) printf("%d ",v[i].first);
	//printf("\n%d %d %d\n",N,M,SZ);
	for(int i=0;i<N;i++) ud(gt(v[i].first),v[i].second);
	for(int i=0;i<M;i++) //printf("%d ",qr(gt(q[i])));
		ct=(ct+qr(gt(q[i])))%2007;
	printf("%d",ct);
}
/*
6
12
3 12
5 11
7 13
8 15
14 21
17 23
1
2
4
6
9
10
15
16
18
19
24
22
*/
