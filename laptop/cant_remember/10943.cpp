#include<iostream>
#include<cstring>
using namespace std;
int ck[101][101];
int dp(int s,int t){
	int sum=0;
	if(ck[s][t]!=-1) return ck[s][t];
	if(t<=1) return 1;
	if(s==0) return 1;
	for(int i=0;i<=s;i++)
		sum += dp(s-i,t-1);
	sum %=1000000;
	return ck[s][t]=sum;
}
int main(){
	int n,m;
	while(true){
		memset(ck,-1,sizeof(ck));
		cin >> n >> m;
		if(n==0&&m==0) return 0;
		cout << dp(n,m) << endl;
	}
}
