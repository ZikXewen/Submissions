#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n;
set<pair<vector<int>,int> > v;
int main(){
	freopen("file.txt","w",stdout);
	while(cin >> n && n){
		v.clear();
		int cnt=0,mx=1;
		for(int i=0;i<n;i++){
			vector<int> inp;
			for(int j=0;j<5;j++){
				int tem; cin >> tem; inp.push_back(tem); 
			}
			sort(inp.begin(),inp.end());
			auto it=v.lower_bound(make_pair(inp,1));
			if(it!=v.end() && it->first==inp){
				v.insert(make_pair(it->first,it->second+1));
				if(it->second+1>mx) mx++;
				v.erase(it);
			}
			else v.insert(make_pair(inp,1));
		}
		for(auto x:v){
			if(x.second==mx) cnt+=mx;
		}
		cout << cnt << endl;
	}
	fclose(stdout);
}
