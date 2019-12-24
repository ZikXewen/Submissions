#include<cstdio>
using namespace std;
int N,v[100005],i1,i2;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&v[i]); v[i]=v[i-1]+v[i];
	}
	int m=v[N]>>1;
	while(i2++!=N){
		while(v[i2]-v[i1]>m) i1++;
		if(v[i2]-v[i1]==m) break;
	}
	if(i2>N) printf("NO");
	else if(i1==0) printf("%d",i2);
	else printf("%d %d",i1, i2);
}
