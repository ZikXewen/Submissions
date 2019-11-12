#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		int a[n][n],mx=-1270000;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
				if(i>0) a[i][j]+=a[i-1][j];
				if(j>0) a[i][j]+=a[i][j-1];
				if(i>0&&j>0) a[i][j]-=a[i-1][j-1];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int x=i;x<n;x++){
					for(int y=j;y<n;y++){
						int cur=a[x][y];
						if(i>0) cur-=a[i-1][y];
						if(j>0) cur-=a[x][j-1];
						if(i>0&&j>0) cur+=a[i-1][j-1];
						if(cur>mx) mx=cur;
					}
				}
			}
		}
		cout << mx << endl;	
	}
}
