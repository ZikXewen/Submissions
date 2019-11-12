#include<iostream>
#include<algorithm>
#define MX 2005
#define MNI -2e9
using namespace std;
int lft[MX][MX],rgt[MX][MX],ver[MX][MX];
int n,m,k,in,mn=MNI;
void Input(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		cin >> in;
		lft[i][j]=lft[i-1][j-1]+in;
		rgt[i][j]=rgt[i-1][j+1]+in;
		ver[i][j]=ver[i-1][j]+in;
	}
}
void calx(){
	for(int i=k;i<=n;i++){
		int tem=0;
		for(int j=1;j<=k;j++) tem+=lft[i][j];
		mn=max(mn,tem);
		for(int j=k+1;j<=m;j++){
			tem=tem-ver[i][j-k]-lft[i-k][j-k]+ver[i-k][j-k]+lft[i][j];
			//cout << tem << ' ';
			mn=max(mn,tem);
		}
	}
}
void caly(){
	for(int i=k;i<=n;i++){
		int tem=0;
		for(int j=m;j>m-k;j--) tem+=rgt[i][j];
		mn=max(mn,tem);
		for(int j=m-k;j>0;j--){
			tem=tem-ver[i][j+k]-rgt[i-k][j+k]+ver[i-k][j+k]+rgt[i][j];
			mn=max(mn,tem);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	calx();
	caly();
	cout << mn;
}
/*
6 7 4
-99 -99 -99 -99 -99 -99 -99
-99 -5 -99 -99 -99 -99 -99
-99 -5 -5 -99 -99 -99 -4
-99 -5 -5 -5 -99 -5 -6
-99 -5 -5 -5 -2 -5 -6
-99 -99 -99 -7 -5 -5 -4 
*/
