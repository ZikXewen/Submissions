#include<cstdio>
using namespace std;
int N,M;
char in;
bool a[35][35],b[35][35];
bool flood(int x,int y){ //printf("%d %d\n",x,y);
	if(x==N) return true;
	a[x][y]=false;
	if(a[x][y+1]&&flood(x,y+1)) return true;
	if(a[x][y-1]&&flood(x,y-1)) return true;
	if(a[x+1][y]&&flood(x+1,y)) return true;
	if(a[x-1][y]&&flood(x-1,y)) return true;
	return false;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) for(int j=0;j<=M;j++) {scanf("%c",&in); if(in=='.') b[i][j]=true;}
	for(int i=2;i<=N;i++) for(int j=2;j<=M;j++) if(b[i][j]&&b[i-1][j]&&b[i-1][j-1]&&b[i][j-1]) a[i][j]=true;
	//for(int i=2;i<=N;i++) {for(int j=2;j<=M;j++) printf("%d",a[i][j]); printf("\n");}
	for(int j=2;j<=M;j++) if(a[2][j]&&flood(2,j)){
		printf("yes"); return 0;
	}
	printf("no");
}
/*
10 10
#..#######
#..#......
#.........
#.....##..
######....
####......
###.....##
###...####
###..#####
###..#####
*/
