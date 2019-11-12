#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#define ii pair<int,int>
#define iii pair<int,ii>
#define MXN 1004
using namespace std;
priority_queue<iii> q;
iii X;
ii n[MXN];
int N,K,ct,p[MXN];
int wei(int x,int y){
	return (n[x].first-n[y].first)*(n[x].first-n[y].first)+(n[x].second-n[y].second)*(n[x].second-n[y].second);
}
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
bool un(int x,int y){
	int pu=fd(x),pv=fd(y);
	if(pu==pv) return false;
	p[pu]=pv; return true;
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		p[i]=i;
		scanf("%d%d",&n[i].first,&n[i].second);
		for(int j=0;j<i;j++) q.push({-wei(i,j),{i,j}});
	}
	ct=N;
	while(ct>K){
		X=q.top(); q.pop();
//		for(int i=0;i<N;i++) printf("%d ",p[i]);
//		printf("\n%d (%d, %d)\n", X.first,X.second.first, X.second.second);
//		printf("\n");
		if(un(X.second.first,X.second.second)) {
			ct--;
		}
	}
	printf("%d",-X.first);
}
