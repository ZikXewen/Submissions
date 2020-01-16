#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,mx=0,a,mn=100000001; vector<int> v;
bool fnd=false;
int val(int ck){
	int ret=0; for(int i:v) ret+=i/ck;
	return ret;
}
int bins(int st,int ed){
	if(ed<st) return ed;
	int md=(st+ed)/2,ansmid=val(md);
	if(ansmid==m) fnd=true;
	if(ansmid<m) return bins(st,md-1);
	return bins(md+1,ed);
}
int main(){
	cin >> n >> m;
	while(n--){
		cin >> a; v.push_back(a);
		mx=max(a,mx);
		mn=min(a,mn);
	}
	int ans = bins(mn,mx+1);
	if(fnd) cout << "YES\n" << ans;
	else cout << "NO\n" << ans;
}
