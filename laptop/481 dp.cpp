#include<iostream>
#include<vector>
using namespace std;
int mxm=-1,mi;
vector<int> v,ans;
vector<pair<int,int> > ck(2000,make_pair(-1,-1));
pair<int,int> dp(int n){
	if(ck[n]!=make_pair(-1,-1)) return ck[n];
	if(n==0) return ck[n]=make_pair(1,-1);
	int mx=0,pt=0;
	for(int i=n-1;i>=0;i--){
		if(v[i]<v[n]&&dp(i).first>mx){
			mx=dp(i).first+1;
			pt=i;
		}
	}
	if(mxm<mx){
		mxm=mx;
		mi=n;
	}
	return ck[n]=make_pair(mx,pt);
}
int main(){
	int a;
	while(cin >> a)
		v.push_back(a);
	for(int i=0;i<v.size();i++) dp(i);
	ans.push_back(v[mi]);
	cout << mxm << endl << "-" << endl;
	while(mi>0)	ans.push_back(v[mi=dp(mi).second]);
	for(int k=ans.size()-1;k>=0;k--) cout << ans[k] << endl;
}
