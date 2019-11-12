#include<iostream>
#include<cstring>
using namespace std;
int n,k,m;
int ck[51][51];
int dp(int ct,int pos){
	if(ck[ct][pos]!=-1) return ck[ct][pos];
	int o=0;
	if(ct>k||n-pos<k-ct) return 0;
	if(pos==n) return 1;
	for(int a=1;a<=m;a++){
		o+=dp(ct+1,pos+a);
	}
	return ck[ct][pos]=o;
}
int main(){
	while(cin >> n){
		cin >> k >> m;
		memset(ck,-1,sizeof(ck));
		cout << dp(0,0) << endl;
	}
	return 0;
}
