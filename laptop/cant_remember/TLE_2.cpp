#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
list<int> v,l;
int n,_a,ct=0;
void Input(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> _a;
		v.push_back(_a);
		l.push_back(_a);
	}
	l.sort();
}
void Lug(){
	for(int i:v){
		auto it=upper_bound(l.begin(),l.end(),i),pt=it; int dis=0;
		while(pt++!=l.end()) dis++;
		ct+=i*dis;
		l.erase(--it);
	}
	cout << ct;
}
int main(){
	Input();
	Lug();
}
