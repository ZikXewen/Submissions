#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> > v;
int m;
bool x;
// v[0],v[1] aren't in the list
void dfs(int lst,int ct,int bit){
	if(ct==m){
		if(lst==v[1].first) x=true;
		return;
	}
	for(int i=2;i<v.size();i++){
		if(1 << i & bit) continue;
		if(v[i].first==lst) dfs(v[i].second,ct+1,bit+(1<<i));
		if(v[i].second==lst) dfs(v[i].first,ct+1,bit+(1<<i));
	}
}
int main(){
	int n,p,q;
	while(cin >> m){
		x=false;
		v.clear();
		if(m==0) return 0; 
		cin >> n;
		for(int i=0;i<n+2;i++){
			cin >> p >> q;
			v.push_back(make_pair(p,q));
		}
		dfs(v[0].second,0,0);
		if(x) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
