#include<cstdio>
#include <cstring>
using namespace std;
int T,N,x,y,a,b,ft[1025][1025]; char s[5];
void ud(int x,int y,int v){
	for(int i=x;i<=N;i+=-i&i) for(int j=y;j<=N;j+=-j&j) ft[i][j]+=v;
}
int gt(int x,int y){
	int ret=0;
	for(int i=x;i;i-=-i&i) for(int j=y;j;j-=-j&j) ret+=ft[i][j];
	return ret;
}
int gt(int x,int y,int a,int b){
	return gt(y+1,b+1)-gt(y+1,a)-gt(x,b+1)+gt(x,a);
}
int main(){
	scanf("%d",&T); while(T--){
		memset(ft, 0, sizeof ft);
		scanf("%d",&N);
		while(scanf(" %s",s)&&strcmp(s, "END")){
			if(!strcmp(s,"SET")){
				scanf("%d%d%d",&x,&y,&a); ud(x+1,y+1,a-gt(x,x,y,y));
			}else{
				scanf("%d%d%d%d",&x,&y,&a,&b);
				printf("%d\n",gt(x,a,y,b));
			}
		}
		if(T) printf("\n");
	}
}
