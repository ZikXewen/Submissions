#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
priority_queue<pair<double,int> > v;
double fx(int t){
	double ans=0;
	while(t!=0){
		auto x=v.top();v.pop();
		if(x.second>t){
			v.push(make_pair(x.first,x.second-t)); ans-=t*x.first; break;
		}
		t-=x.second; ans-=x.second*x.first;
	}
	return ans;
}
int main(){	
	int k; cin >> k; cout << setprecision(3) << fixed;
	for(int i=0;i<k;i++){
		int t1,t2; cin >> t1 >> t2;
		v.push(make_pair(-(double(t1))/t2,t2));
	}
	cin >> k; for(int i=0;i<k;i++){
		int t; cin >> t; cout << fx(t) << endl;
	}
}
