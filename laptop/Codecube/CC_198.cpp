#include <bits/stdc++.h>
using namespace std;
const int _N = 2e5+5;
const int _K = 11;
int N,M,k,t[_N],ft[_K],lps[_K][_N],an1;
vector<int> p[_K];
bool an[_K][_N];
void kmp(){
	for(int i=0;i<=k;i++){ // i -> pattern #
		for(int j=0,k=0;j<N;){ // j -> text , k -> pattern
			if(t[j]==p[i][k]) j++,k++; // text match pattern
			if(k==p[i].size()) an[i][j-k-ft[i]]=1, k=lps[i][k-1]; // reach end
			else if(j<N&&t[j]!=p[i][k]){ // miss
				if(k) k=lps[i][k-1];
				else j++;
			}
		}
	}
}
void glps(){
	for(int i=0;i<=k;i++){
		for(int j=1,lst=0;j<p[i].size();){
			if(p[i][j]==p[i][lst]) lps[i][j++]=++lst;
			else if(lst) lst=lps[i][lst-1];
			else lps[i][j++]=0;
		}
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&t[i]);
	for(int i=0,x;i<M;i++){
		scanf("%d",&x);
		if(x==1) {if(p[k].size()) k++;}
		else{
			if(p[k].empty()) ft[k]=i;
			p[k].emplace_back(x);
		}
	}
	if(p[k].empty()) k--;
	glps();
	kmp();
	for(int i=0,ck=0;i<=N-M;i++,ck=0){
		for(int j=0;j<=k;j++)  if(!an[j][i]) {ck=1; break;}
		if(!ck) an1++;
	}
	printf("%d",an1);
}
