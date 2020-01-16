#include<cstdio>
#include<iostream>
#define MXN 1000005
#define MOD 2553
using namespace std;
int N,ar[MXN],ct,ans;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&ar[i]);
	for(int i=1;i<=N;i++){
		ct=(ct+i)%MOD; ans=(ans+ar[N-i]*ct)%MOD;
	}
	printf("%d",ans);
}
