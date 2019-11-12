#include<bits/stdc++.h>
using namespace std;
int k,n;
double mm[10][105];
double dp(int cur,int len){
	if(mm[cur][len]) return mm[cur][len];
	if(cur==0) return mm[cur][len]=dp(cur,len+1)+dp(cur+1,len+1);
	if(cur==k) return mm[cur][len]=dp(cur,len+1)+dp(cur-1,len+1);
	return mm[cur][len]=dp(cur,len+1)+dp(cur+1,len+1)+dp(cur-1,len+1);
}
int main(){
    ios_base::sync_with_stdio(false);
	while(cin >> k >> n){
		if(k==0){
			cout << "100.00000\n"; continue;
		}
		double sm=0.0;
		memset(mm,0,sizeof mm);
		for(int i=0;i<10;i++) mm[i][n]=1;
		for(int i=0;i<=k;i++) sm+=dp(i,1);
		cout << setprecision(5) << fixed << 100*sm/pow((double)k+1,n) << endl;
	}
}
