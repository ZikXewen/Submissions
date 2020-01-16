#include<cstdio>
using namespace std;
int N,cmd,a,b,c,d,ft[1030][1030];
void ud(int x,int y,int v){
	for(int i=x;i<=N;i+=-i&i)
		for(int j=y;j<=N;j+=-j&j) ft[i][j]+=v;
}
int qr(int x,int y){
	if(!x||!y) return 0;
	int ret=0;
	for(int i=x;i>0;i-=-i&i)
		for(int j=y;j>0;j-=-j&j) ret+=ft[i][j];
	return ret;
}
int gt(int x1,int y1,int x2,int y2){
	return qr(x2,y2)-qr(x1,y2)-qr(x2,y1)+qr(x1,y1);
}
int main(){
	//freopen("inp.txt","r",stdin);
	scanf("%d%d",&cmd,&N);
	while(cmd!=3){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d%d%d",&a,&b,&c);
			ud(a+1,b+1,c);
		}
		if(cmd==2){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			printf("%d\n",gt(a,b,c+1,d+1));
		}
	}
	//fclose(stdin);
}
