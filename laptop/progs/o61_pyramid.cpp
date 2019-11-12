#include<bits/stdc++.h>
using namespace std;
const int MXL = 10010;
int N,ft[MXL][MXL],u,v;
void ud(int x,int y){
	for(int i=x;i<=MXL;i+=-i&i) for(int j=y;j<=MXL;j+=-j&j) ft[i][j]++;
}
int gt(int x,int y){
	int ret=0;
	for(int i=x;i;i-=-i&i) for(int j=y;j;j-=-j&j) ret+=ft[i][j];
	return ret;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) {scanf("%d%d",&u,&v); printf("%d\n",gt(u-v+5000,10000-u-v)); ud(u-v+5000,10000-u-v);}
}
