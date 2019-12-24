#include<bits/stdc++.h>
using namespace std;
const int MXN =2e5+5;
int N,M,s[MXN],p[MXN],lps[MXN],an;
void kmp(){
	for(int i=0,j=0;i<N;){
		if(s[i]==p[j]||p[j]==1) i++,j++; // check
		if(j==M) i=i-j+1,j=0,an++; // finish pattern
		else if(i<N&&s[i]!=p[j]&&p[j]!=1){ // not finish pattern nor text & found mismatch
			if(j) j=lps[j-1]; // return
			else i++; // continue
		}
	}
}
void glps(){
	for(int i=1,lst=0;i<M;){
		if(p[i]==p[lst]) lps[i++]=++lst;
		else if(lst) lst=lps[lst-1];
		else lps[i++]=0;
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&s[i]);
	for(int i=0;i<M;i++) scanf("%d",&p[i]);
	glps();
	kmp();
	printf("%d",an);
}