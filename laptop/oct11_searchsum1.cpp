#include<cstdio>
#include<algorithm>
using namespace std;
int N,K,q,v[100005];
int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++){
		scanf("%d",&v[i]); v[i]+=v[i-1];
	}
	while(K--){
		scanf("%d",&q);
		printf("%d\n",upper_bound(v,v+N+1,q)-v-1);
	}
}
