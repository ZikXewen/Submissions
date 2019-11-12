#include<stdio.h>
int row,col,r[100][100];
int Invalid(int a, int b, int c, int d){
	if(a>c||b>d) return 1;
	return 0;
}
int Outside(int a,int b, int c, int d){
	if((a>row)||(c<=0)||(b>col)||(d<=0)) return 1;
	return 0;
}
int Check(int a, int b, int c, int d){
	int i,j,max;
	for(i=a-1;i<c&&i<row;i++){
		for(j=b-1;j<d&&j<col;j++){
			if(r[i][j]>max||(i==a-1&&j==b-1)) max=r[i][j];
		}
	}
	return max;
}
int main(){
	int i,j,n; scanf("%d%d%d",&row,&col,&n);
	int ck[n][4];
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&r[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&ck[i][j]);
		}
	}
	for(i=0;i<n;i++){
		if(Invalid(ck[i][0],ck[i][1],ck[i][2],ck[i][3])==1) printf("INVALID\n");
		else if(Outside(ck[i][0],ck[i][1],ck[i][2],ck[i][3])==1) printf("OUTSIDE\n");
		else printf("%d\n",Check(ck[i][0],ck[i][1],ck[i][2],ck[i][3]));
	}
	return 0;
}
/*
1 2 5 7 8 2
4 3 3 6 2 9
5 -1 2 3 -7 8 
8 9 6 -5 -2 0 
0 1 3 7 -9 0*/
