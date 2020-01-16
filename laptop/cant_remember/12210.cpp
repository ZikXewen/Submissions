#include<iostream>
#include<set>
using namespace std;
int main(){
	int c=0,m,n;
	while(++c){
		cin  >> m >> n;
		if(m==0&&n==0) return 0;
		multiset<int> s;
		for(int i=0;i<m;i++){
			int t;
			cin >> t;
			s.insert(t);
		}
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
		}
		cout << "Case " << c << ": ";
		if(m<=n) cout << "0" << endl;
		else cout << m-n << " " << *s.begin() << endl;
	}
}
