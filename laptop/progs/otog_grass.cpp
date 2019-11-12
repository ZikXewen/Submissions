#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int _n,_m,_a,_b;
vector<int> x,y;
void Input(){
	cin >> _n >> _m;
	for(int i=0;i<_n;i++){
		cin >> _a >> _b;
		x.push_back(_a); y.push_back(_b);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
}
void Grass(){
	int tm=0;
	for(auto i=x.begin();i!=x.end();i++) tm=max(tm,int(lower_bound(x.begin(),x.end(),*i+_m)-i));
	for(auto i=y.begin();i!=y.end();i++) tm=max(tm,int(lower_bound(y.begin(),y.end(),*i+_m)-i));
	cout << tm;
}
int main(){
	Input();
	Grass();
}
