#include<iostream>
#define MXN 1005
using namespace std;
int N,v[MXN],t[MXN];
void mrg(int s,int e){
	if(s==e) return;
	int m=(s+e)>>1,i=s,j=m+1,k=s;
	mrg(s,m); mrg(m+1,e);
	for(int o=s;o<=e;o++) t[o]=v[o];
	while(i<=m&&j<=e){
		if(t[i]<t[j]) v[k++]=t[i++];
		else v[k++]=t[j++];
	}
	while(i<=m) v[k++]=t[i++];
	while(j<=e) v[k++]=t[j++];
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	mrg(0,N-1);
	for(int i=0;i<N;i++) printf("%d\n",v[i]);
}
