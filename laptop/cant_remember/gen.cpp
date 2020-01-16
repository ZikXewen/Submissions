#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n;
void gen(set<int> &s,vector<int> &v){
	set<int> t=s;
	for(int prs: s){
		t.erase(prs);
		v.push_back(prs);
		gen(t,v);
		t.insert(prs);
		v.pop_back();
	}
	if(s.empty()){
		for(int out: v)
			cout << out;
		cout << "\n";
	}
}
int main(){
	cin >> n;
	set<int> s;
	vector<int> v;
	for(int i=0;i<n;i++) s.insert(i);
	gen(s,v);
}
