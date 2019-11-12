#include<cstdio>
#include<vector>
#define MXN 200005
using namespace std;
int N,ft[MXN],v[MXN],a;
void mk(int idx,int no){
	for(;idx<=N;idx+=-idx&idx) ft[idx]+=no;
}
int gt(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int bins(int st,int ed,int fd){
	if(st>=ed){
		mk(st,-1);
		return st;
	}
	int md=(st+ed)/2;
	if(gt(md)>=fd) return bins(st,md,fd);
	return bins(md+1,ed,fd);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&v[i]);
		mk(i,1);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		printf("%d\n",v[bins(1,N,a)]);
	}
}                    
