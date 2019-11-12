#include <bits/stdc++.h>
using namespace std;
class ii{public: int x,y; bool operator<(const ii R)const{if(x!=R.x) return x<R.x; return y<R.y;}};
const int mxn = 10005;
int n,lis[mxn],ta;
ii v[mxn];
int main(){
	freopen("input","r",stdin);
	while(scanf("%d",&n)&&n){
		memset(lis,0,sizeof lis); ta=0;
		for(int i=0;i<n;i++) scanf("%d%d",&v[i].x,&v[i].y);
		sort(v,v+n);
		for(int i=0;i<n;i++) {auto k=upper_bound(lis,lis+ta,v[i].y); if(k==lis+ta) ta++; *k=v[i].y;}
		printf("%d\n",ta);
	} printf("*\n");
}
