#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
set<string> sa;
void bit(vector<int> &v,int t){
	bool x=true;
	cout << "Sums of " << t << ":" << endl;
	for(int i=0;i < 1 << v.size();i++){
		int ans=0;
		vector<int> va;
		for(int j=0;j<v.size();j++){
			if(i & (1 << j)){
				ans+=v[j];
				va.push_back(v[j]);
			}
		}
		if(ans==t){
			string tem; tem+=to_string(va[0]);
			for(int j=1;j<va.size();j++){
				tem=tem+"+"+to_string(va[j]);
			}
			if(sa.find(tem)==sa.end()){
				sa.insert(tem);
			}
			x = false;
		}
	}
	if(x) cout << "NONE" << endl;
}
int main(){
	while(true){
		sa.clear();
		int t,n;
		vector<int> v;
		cin >> t >> n;
		if(t==0&&n==0) return 0;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		bit(v,t);
		for(auto i=sa.end();i!=sa.begin();){
			cout << *(--i) << endl;
		}
	}
}
