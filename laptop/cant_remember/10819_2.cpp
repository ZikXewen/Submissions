#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,arr[10001][101];
vector<pair<int,int> > v; // Weight , Value
int dp(int id,int re){ // Max Amount at id & remaining value
	if(arr[id][re]!=-1) return arr[id][re];
	if(id==n||re==0) return arr[id][re]=0;
	if(v[id].first<=re) return arr[id][re]=max(dp(id+1,re),dp(id+1,re-v[id].first)+v[id].second);
	return arr[id][re]=dp(id+1,re);
}
int main(){
	while(cin >> m >> n){
		memset(arr,-1,sizeof(arr));
		for(int i=0;i<n;i++){
			int p,f; cin >> p >> f;
			v.push_back(make_pair(p,f));
		}
		if(m>1800) cout << dp(0,m+200) << endl;
		else cout << dp(0,m) << endl; 
	}
}
