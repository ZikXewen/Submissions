#include <bits/stdc++.h>
using namespace std;
const int mxn = 105;
int n,m,ar[mxn][mxn],ret;
int main(){
	while(scanf("%d%d",&n,&m)&&(n||m)){
		memset(ar,0,sizeof ar); ret=0;
		for(int i=1,x;i<=n;i++) for(int j=1;j<=m;j++){
			scanf("%d",&x);
			if(!x) ar[i][j]=ar[i][j-1]+1;
		}
		for(int i=1,cr;i<=n;i++) for(int j=m;j>0;j--){
			if(cr=ar[i][j]) for(int k=i;k<=n;k++){
				if(!ar[k][j]) break;
				cr=min(cr,ar[k][j]); ret=max(ret,cr*(k-i+1));
			}
		}
		printf("%d\n",ret);
	}
}
