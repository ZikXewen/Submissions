#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MXN = 1e5+5;
int N,v[MXN],pa[MXN],ta[MXN],ti[MXN],len;
long long ct;
int main(){
	scanf("%d",&N);
	for(int i=0,x;i<N;i++) scanf("%d",&v[i]);
	for(int i=N-1;i>=0;i--){
		int nw=upper_bound(ta,ta+len,-v[i])-ta; // new index
		if(nw==len) ta[len++]=-v[i]; // new tail
		else ta[nw]=-v[i]; // insert tail
		if(nw) pa[i]=ti[nw-1]; // update parent
		ti[nw]=i; // update indice
	}
	for(int i=ti[len-1];;i=pa[i]) {ct+=v[i]; if(!pa[i]) break;}
	printf("%d %lld",len,ct);
}