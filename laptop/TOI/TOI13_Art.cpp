#include<cstdio>
#include<vector>
#define MXN 1000005
#define MXL 4000005
#define ii pair<int,int>
using namespace std;
int N,T,s,h,w,o,ft[MXN],tem;
long long an;
vector<ii> v[MXL];
void ud(int idx,int x){
	for(;idx<MXN;idx+=-idx&idx) ft[idx]+=x;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int lb(int s,int e){
	if(s>e) return s;
	int m=(s+e)>>1;
	if(qr(m)<=T) return lb(s,m-1);
	return lb(m+1,e);
}
int ub(int s,int e){
	if(s>e) return s;
	int m=(s+e)>>1;
	if(qr(m)<T) return ub(s,m-1);
	return ub(m+1,e);
}
int main(){
	scanf("%d%d",&N,&T);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&s,&h,&w,&o);
		v[s].emplace_back(h,o);
		v[s+w].emplace_back(h,-o);
	}
	for(int i=1;i<MXL;i++){
		if(v[i].empty()){
			an+=tem; continue;
		}
		for(ii x:v[i]){ //printf("%d %d %d\n",i,x.first,x.second);
			ud(1,x.second);
			ud(x.first+1,-x.second);
		}
		//for(int i=0;i<10;i++) //printf("%d ",ft[i]); printf("\n");
		an+=(tem=ub(1,MXN)-lb(1,MXN-1));
	}
	printf("%lld",an);
}
