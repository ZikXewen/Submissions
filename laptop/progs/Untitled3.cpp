#include<cstdio>
#include<algorithm>
using namespace std;
int N,v[1005],mt[1005];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	next_permutation(v,v+N);
	for(int i=0;i<N;i++) printf("%d\n",v[i]);
}
