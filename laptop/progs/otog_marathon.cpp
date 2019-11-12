#include<iostream>
#define INF 1e9
using namespace std;
int m,n,s,a,b,c,ar[101][101];
int main(){
	cin >> m >> n >> s;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) ar[i][j]=INF;
	while(n--){
		cin >> a >> b >> c;
		ar[a][b]=c;
		ar[b][a]=c;
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);
	for(int i=0;i<m;i++) if(ar[i][i]<=s){
		cout << ar[i][i] << "YES"; return 0;
	}
	cout << "NO";
}
