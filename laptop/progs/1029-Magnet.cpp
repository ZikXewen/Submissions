#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int n,m,q; cin >> n >> m >> q;
	set<int> v={0};
	while(m--){
		int a,k; cin >> a >> k;
		auto x = v.insert(a); if(!x.second) v.erase(x.first);
		x = v.insert(a+k); if(!x.second) v.erase(x.first);
	}
	for(int i=0;i<q;i++){
		int que; cin >> que;
		auto it=v.upper_bound(que);
		if(it==v.begin()) cout << *it-1 << endl;
		else if(it==v.end()) cout << n-*(--it) << endl;
		else cout << *it-*(--it) << endl;
	}
}
