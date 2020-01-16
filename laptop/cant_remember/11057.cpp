#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int> s;
	int n;
	while(cin >> n){
		int max=0;
		s.clear();
		for(int i=0;i<n;i++){
			int k;
			cin >> k;
			s.insert(k);
		}
		cin >> n;
		if(*(++s.lower_bound(n/2))==n/2) max=n/2;
		else for(auto it=s.begin();it!=s.upper_bound(n/2);it++){
			if(s.find(n-*it)!=s.end()&&*it>max) max=*it;
		}
		cout << "Peter should buy books whose prices are " << max << " and " << n-max << ".\n\n" ;
	}
	return 0;
}
