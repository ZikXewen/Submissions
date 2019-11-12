#include<cstdio>
#include<algorithm>
#define MXN 100005
using namespace std;
int N,x[MXN],y[MXN];
bool ck(int X){
	return (upper_bound(x,x+N,X)-x)+(upper_bound(y,y+N,X)-y) >= N;
}
int b_search(int s,int e){
	if(s==e) return s;
	int m=(s+e)>>1;
	if(ck(m)) return b_search(s,m);
	return b_search(m+1,e);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&x[i]);
	for(int i=0;i<N;i++) scanf("%d",&y[i]);
	sort(x,x+N); sort(y,y+N);
	printf("%d",b_search(1,1000000000));
}
