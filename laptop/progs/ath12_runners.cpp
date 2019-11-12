#include<cstdio>
#include<algorithm>
using namespace std;
class ii{
	public:
		double w;
		int t,no;
};
bool comp(ii L,ii R){
	if(L.w==R.w) return L.t>R.t;
	return L.w<R.w;
}
int T,N,v,t,M;
ii V[35];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			scanf("%d%d",&v,&t);
			V[i]={double(1000*M)/v+t,t,i};
		}
		sort(V,V+N,comp);
		for(int i=0;i<N;i++) printf("%d\n",V[i].no+1);
	}
}
