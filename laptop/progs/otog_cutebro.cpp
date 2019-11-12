#include<iostream>
#include<vector>
using namespace std;
int n,m,a;
vector<int> v,vec;
vector<vector<int> > ans;
void bk(int sm){
	if(sm==n){
		ans.push_back(vec);
		return;
	}
	if(vec.size()==m) return;
	for(int i:v){
		vec.push_back(i); bk(sm+i); vec.pop_back();
	}
}
int main(){
	cin >> n >> m;
	for(int i=0;i<6;i++){
		cin >> a; v.push_back(a);
	}
	bk(0);
	cout << ans.size() << "\nE\n";
	for(auto it=ans.begin();it!=ans.end();it++){
		cout << it->size();
		for(int i:*it) cout << " " << i;
		cout << "\nE\n";
	}
}
