#include<bits/stdc++.h>
using namespace std;
int N,M,A[700005];
int bsearch(int x){
	int s=1;
	for(int e=N+1,m;s<e;){
		m=(s+e)>>1;
		if(x<=A[m]-m) e=m;
		else s=m+1;
	}
	return s;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	sort(A+1,A+N+1); A[N+1]=2e9;
	for(int i=0,x,y;i<M;i++){
		scanf("%d",&x);
		y=bsearch(x);
		printf("%d ",x+y-1);
	}

}
/*

*/