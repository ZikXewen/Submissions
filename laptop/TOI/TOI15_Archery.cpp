#include <bits/stdc++.h>
using namespace std;
const int _N = 5e5+5;
int N;
int u[_N],v[_N],a[_N],mn=2e9,k;
long long cur;
bool comp(const int&L,const int &R){return u[L]<u[R];}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&v[i]), mn=min(mn,v[i]);
	for(int i=0;i<N;i++) scanf("%d",&u[i]), a[i]=i, cur+=u[i]-1;
	sort(a,a+N,comp);
	a[0]
	for(int i=1;i<N&&a[i]<=mn;i++){
		cout << cur << endl;
		if(a[i]==a[i-1]) k+=v[a[i]];
		else cur+=k,k=0;
		cur+=(a[i]-a[i-1])*N;
	}
}
