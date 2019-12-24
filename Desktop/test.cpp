#include<bits/stdc++.h>
using namespace std;
queue<int> v;
void pt(){
	cout << "size" << v.size() << ": ";
	cout << v.front() << ' ';
	cout << endl;
}
int main(){
	v.push(6);
	pt();
	v.pop();
	v.pop();
	pt();
}