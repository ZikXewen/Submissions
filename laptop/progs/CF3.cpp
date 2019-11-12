#include<cstdio>
#include<iostream>
#define MXN 200005
using namespace std;
int N,K,v[MXN],sm,qs,ct,a,mn=MXN;
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) {scanf("%d",&a); v[a]++; mn=min(mn,a);}
	for(int i=MXN-1;i>mn;i--){
		sm+=v[i]; qs+=sm; //printf("%d\n",qs);
		if(qs>K){
			qs=sm; ct++;
		}
	}
	if(qs) ct++;
	cout << ct;
}
