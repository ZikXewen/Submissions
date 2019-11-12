#include<iostream>
#include<set>
using namespace std;
int main(){
	set<pair<int,int> > a;
	int i,n,chk;
	cin >> n;
	int inp[n];
	for(i=0;i<n;i++){
		cin >> inp[i];
		a.insert(make_pair(inp[i],i));
	}
	cin >> chk;
	a.erase(a.lower_bound(make_pair(chk+1,-1)),a.end());
	for(auto j=a.begin();j != a.end();j++){
		cout << j->first;
	}
}
