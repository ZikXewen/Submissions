#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,q,v[200005];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	sort(v,v+N);
	while(M--){
		scanf("%d",&q);
		if(binary_search(v,v+N,q)) printf("y\n");
		else printf("n\n");
	}
}
