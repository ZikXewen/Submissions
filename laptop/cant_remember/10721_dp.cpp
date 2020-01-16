#include<iostream>
#include<cstring>
using namespace std;
int n,k,m;
long long ck[51][51][51];
long long dp(int l,int f,int ct){
	if(ck[l][f][ct]!=-1) return ck[l][f][ct];
	if(ct>k) return ck[l][f][ct]=0;
	if(f>m) return ck[l][f][ct]=0;
	if(l==0 )
		if(ct==k) return ck[l][f][ct]=1;
		else return ck[l][f][ct]=0;
	return ck[l][f][ct]=dp(l-1,1,ct+1)+dp(l-1,f+1,ct);
}
int main(){
	while(cin >> n){
		memset(ck,-1,sizeof(ck));
		cin >> k >> m;
		cout << dp(n-1,1,1) << endl; 
	}
}
