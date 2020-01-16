#include<cstdio>
#include<algorithm>
using namespace std;
int N,v[150005],sm,x;
int main(){
	scanf("%d",&N); x=N/5;
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]); sm+=v[i];
	}
	sort(v,v+N);
	for(int i=1;i<=x;i++) sm-=v[N-(i<<1)];
	printf("%d",sm);
}
