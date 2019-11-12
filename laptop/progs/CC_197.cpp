#include <bits/stdc++.h>
using namespace std;
const int MXN = 1505;
const int MXK = 55;
int N,K,v[MXN],tab[MXN][MXN],dp[MXK][MXN];
void prep(){
	for(int i=1;i<=N;i++) {
		priority_queue<int> l,r; // r -'d
		for(int j=i,ll=0,rr=0;j<=N;j++){
			r.emplace(-v[j]); rr+=v[j];
			if(!l.empty()&&-r.top()<l.top()){
				int tl=l.top(),tr=r.top(); l.pop(); r.pop();
				l.emplace(-tr); r.emplace(-tl);
				ll+=tr+tl, rr+=tr+tl;
			}
			if(l.size()+2==r.size()) l.emplace(-r.top()), ll+=r.top(), rr+=r.top(), r.pop();
			tab[i][j] = ll + rr + r.top() * (r.size()-l.size());
		}
	}
}
void dyn(){
	fill_n(dp[0],MXK*MXN,(int)1.5e9);
	dp[0][0]=0;
	for(int i=1;i<=K;i++) for(int j=1;j<=N;j++) for(int k=1;k<=j;k++)
		dp[i][j]=min(dp[i][j],dp[i-1][k-1]+tab[k][j]);
}
int main(){
	scanf("%d%d",& N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	prep();
	dyn();
	printf("%d",dp[K][N]);
}
