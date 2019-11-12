#include <bits/stdc++.h>
using namespace std;
const int mxn = 105 , mxk = 5000;
int n,m,v[mxn];
bool ks[mxk];
int main(){
	while(scanf("%d%d",&n,&m)&&(n||m)){
		memset(ks,0,sizeof ks);
		for(int i=1,x,y;i<=n;i++)scanf("%d.%d",&x,&y), v[i]=100*x+y;
		if(v[m]>mxk) {printf("100.00\n"); continue;} 
		ks[0]=1;
		for(int i=1;i<=n;i++) if(i!=m) for(int j=mxk-1;j>=v[i];j--) ks[j]|=ks[j-v[i]];
		for(int i=mxk-1;i>0;i--) if(ks[i]) { printf("%.2f\n",100*v[m]/(1e4-i)); break;}
	}
}
