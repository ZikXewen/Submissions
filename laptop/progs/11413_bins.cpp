#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> v;
bool ck(int a){
	int ct=1,sm=0;
	for(int x:v){
		sm+=x;
		if(sm>a){
			if(++ct>m||x>a) return false;
			sm=x;
		}
	}
	return true;
}
int bs(int st,int ed){
	if(ed<st) return st;
	int mid=(st+ed)/2;
	//cout << mid << endl;
	if(ck(mid)) return bs(st,mid-1); //if yes, check lower
	return bs(mid+1,ed);
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> n){
		cin >> m;
		v.clear();
		for(int i=0;i<n;i++){
			int t; cin >> t; v.push_back(t);
		}
		cout << bs(1,1000000000) << endl;
	}
	//fclose(stdout);
}
