#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,mx,i1,i2,cur,v[300005];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	while(i1!=N&&i2!=N){
		cur+=v[i1++];
		while(cur>M) cur-=v[i2++];
		mx=max(mx,cur);
	}
	printf("%d",mx);
}
