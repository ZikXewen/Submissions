#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+5;
int N,W,v[MXN],st[MXN],fd[MXN],ft[MXN];
bool comp(const int &L,const int &R){
	if(v[L]==v[R]) L<R;
	return v[L]>v[R];
}
void inp(){
	scanf("%d%d",&N,&W);
	for(int i=1;i<=N;i++) {scanf("%d",&v[i]); st[i]=i;}
}
void bd(){
	for(int idx=1;idx<=N;idx++) for(int idx2=idx;idx2<=N;idx2+=-idx2&idx2) ft[idx2]++; 
}
void ud(int idx){
	for(;idx<=N;idx+=-idx&idx) ft[idx]--;
}
int gt(int idx){ 
	int ret=0; for(;idx;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int bs(int s,int e,int x){
	if(s>e) return e;
	int m=(s+e)>>1;
	if(gt(m)==x) return bs(m+1,e,x);
	return bs(s,m-1,x);
}
int rbs(int s,int e,int x){
	if(s>e) return s;
	int m=(s+e)>>1;
	if(gt(m)==x) return rbs(s,m-1,x);
	return rbs(m+1,e,x);
}
void algo(){
	for(int i=1;i<=N;i++){ 
		ud(st[i]);
		int nxt=bs(st[i],N,gt(st[i]));
		if(v[st[i]]!=v[st[i+1]] || nxt+1!=st[i+1]) {
			int prev=rbs(0,st[i],gt(st[i]))+1;
			if(fd[nxt-prev]==-1) fd[nxt-prev]=v[st[i]];
		}
	}
}
int main(){
	memset(fd,-1,sizeof fd);
	inp();
	sort(st+1,st+N+1,comp);
	bd();
	algo();
	if(W==-10) for(int i=1;i<=N;i++) printf("%d ",fd[i]);
	else printf("%d",fd[W]);
}
/*
8 -10
3 4 2 3 5 4 3 1
*/
