#include<iostream>
#include<set>
using namespace std;
int main(){
	int n,m;
	while(true){
		int sm=0;
		cin >> n >> m;
		if(n==0&&m==0) return 0;
		int a[n];
		multiset<int> s;
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<m;i++) {
			int t;
			cin >> t;
			s.insert(t);
		}
		
		for(int i=0;i<n;i++){
			if(s.lower_bound(a[i])==s.end()){
				cout << "Loowater is doomed!" << endl;
				sm=0;
				break;
			}
			else{
				sm+=*s.lower_bound(a[i]);
				s.erase(s.lower_bound(a[i]));
			}
		}
		if(sm!=0) cout << sm << endl;
	}
}
