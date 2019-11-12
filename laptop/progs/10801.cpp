#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
vector<int> t;
bool ck[100],v[5][100];
int n,k;
int spth(){
	priority_queue<pair<int,pair<int,int> > > q; //Current Time, Current Floor, Current Elevator
	while(!q.empty()) q.pop();
	q.push(make_pair(0,make_pair(0,-1)));
	while(!q.empty()){
		auto x=q.top(); q.pop();
		//cout << x.first << " " << x.second.first << endl;
		if(ck[x.second.first]) continue;
		if(x.second.first==k) return x.first;
		ck[x.second.first]=true;
		for(int i=0;i<n;i++){
			if(v[i][x.second.first]&&i!=x.second.second){
				for(int j=0;j<100;j++){
					if(v[i][j]&&j!=x.second.first) q.push(make_pair(x.first-(t[i]*abs(j-x.second.first))-60,make_pair(j,i)));
				}
			}
		}
	}
	return 1;
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> n >> k){
		t.clear();
		memset(v,false,sizeof(v)); memset(ck,false,sizeof(ck));
		string s;
		for(int i=0;i<n;i++){
			int tem; cin >> tem; t.push_back(tem);
		}
		getline(cin,s);
		for(int i=0;i<n;i++){
			getline(cin,s);
			stringstream ss(s);
			while(ss){
				int tem; ss >> tem; v[i][tem]=true;
			}
		}
		int tem=spth();
		if(tem<0) cout << -tem-60 << endl;
		else if(tem==1) cout << "IMPOSSIBLE" << endl;
		else cout << 0 << endl;
	}
	//fclose(stdout);
}
