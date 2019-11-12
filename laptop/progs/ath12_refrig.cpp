#include<cstdio>
#include<algorithm>
#define MXM 305
using namespace std;
int N,T,v[205];
bool ck(int x){
	int ct=0;
	for(int i=0;i<N;i++){
		ct+=max(x-v[i],0);
		if(ct>=x) return false;
	}
	return true;
}
int b_search(int s,int e){
	if(s==e) return s;
	int m=(s+e)>>1;
	if(!ck(m)) return b_search(s,m);
	return b_search(m+1,e);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%d",&v[i]);
		printf("%d\n",b_search(1,MXM)-1);
	}
}
