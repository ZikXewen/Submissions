#include <bits/stdc++.h>
using namespace std;
const int _N = 5e5+5;
int N,a[_N],b[_N],mx,mn=2e9;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	for(int i=0;i<N;i++) scanf("%d",&b[i]);
	sort(a,a+N); sort(b,b+N,greater<int>());
	for(int i=0;i<N;i++) mx=max(mx,a[i]+b[i]),mn=min(mn,a[i]+b[i]);
	printf("%d",mx-mn);
}
