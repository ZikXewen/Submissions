#include<bits/stdc++.h>
using namespace std;
int main(){
	scanf("%d%d%d",&N,&M,&X);
	for(int i=0;i<N;i++) scanf("%d",&l[i]);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	for(int i=1;i<=M;i++) scanf("%d",&s[i]);
	for(int i=0;i<X;i++) scanf("%d",&t[i]);
	for(int i=0;i<X;i++){
		for(int i=0;i<N;i++) scanf("%d",&q[i]);
	}
}