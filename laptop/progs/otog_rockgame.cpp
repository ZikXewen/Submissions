#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v; int a,n;
int mem[101][101][2];
int dp(int l,int r,bool trn){
	if(l==r) return 0;
	if(mem[l][r][trn? 1:0]) return mem[l][r][trn? 1:0];
	if(trn) return mem[l][r][1]=max(dp(l,r-1,false),dp(l+1,r,false));
	return mem[l][r][0]=max(dp(l,r-1,true)+v[r],dp(l+1,r,true)+v[l]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n; for(int i=0;i<2*n;i++){
		cin >> a; v.push_back(a);
	}
	cout << dp(0,2*n-1,false);
}
