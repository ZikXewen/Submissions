#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int main(){
	int n,l,w;
	set<pair<int,int>> s;
	cin >> n >> l >> w;
	for(int i=0;i<n;i++){
		int len,po,ra;
		cin >> po >> ra;
		if(ra<(w/2)) {
			s.insert(make_pair(0,0));
			continue;
		}
		len=sqrt((ra*ra)-(w*w/4));
		s.insert(make_pair(po-len,po+len));
	}
}
