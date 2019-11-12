#include<iostream>
#include<cstring>
using namespace std;
int a[20][21]={},x,tab[201][20];
int dp(int m,int i){
	if(m<0) return 201;
	if(i==x) return m;
	if(tab[m][i]!=-1) return tab[m][i];
	int mn=201;
	for(int o=0;a[i][o]!=0;o++){
		mn=min(mn,dp(m-a[i][o],i+1));
	}
	return tab[m][i] = mn;
}
int main(){
	int c,mo,y;
	cin >> c;
	while(c--){
		memset(tab,-1,sizeof(tab));
		cin >> mo >> x;
		for(int i=0;i<x;i++){
			cin >> y;
			for(int j=0;j<y;j++){
				cin >> a[i][j];	
			}
			a[i][y]=0;
		}
		if(dp(mo,0)!=201) cout << mo-dp(mo,0) << endl;
		else cout << "no solution\n";
	}
}
