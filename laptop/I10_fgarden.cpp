#include<cstdio>
#include<algorithm>
using namespace std;
bool b[35][35];
int N,M,v[35][35],mx;
int flood(int x,int y){
	int ret=1;
	b[x][y]=false;
	if(b[x+1][y]) ret+=flood(x+1,y);
	if(b[x-1][y]) ret+=flood(x-1,y);
	if(b[x][y+1]) ret+=flood(x,y+1);
	if(b[x][y-1]) ret+=flood(x,y-1);
	return ret;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) for(int j=0;j<=M;j++) scanf("%c",&v[i][j]);
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(v[i][j]!='#'&&v[i+1][j]!='#'&&v[i-1][j]!='#'&&v[i][j+1]!='#'&&v[i][j-1]!='#') b[i][j]=true;
	//for(int i=1;i<=N;i++) {for(int j=1;j<=M;j++) printf("%d",b[i][j]); printf("\n");}
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(b[i][j]) mx=max(mx,flood(i,j));
	printf("%d",mx);
}
