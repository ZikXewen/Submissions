#include<cstdio>
#include<algorithm>
#define MX 2e9
#define MXN 10005
using namespace std;
int N,M,v[MXN],mx;
int ck(int x){
	int sm=0,ct=1;
	for(int i=0;i<N;i++){
		sm+=v[i];
		if(sm>x){
			ct++;
			sm=v[i];
		}
	}
	return ct;
}
int b_search(int s,int e){
	if(s>e) return e;
	int m=(s+e)>>1;
	if(ck(m)<M) return b_search(s,m-1);
	return b_search(m+1,e);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
		mx=max(mx,v[i]);
	}
	int an=b_search(mx+1,MX);
	if(ck(an)==M) printf("%d",an);
	else printf("IMPOSSIBLE");
}
