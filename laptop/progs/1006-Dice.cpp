#include<iostream>
#include<string>
#include<array>
using namespace std;
void roll(char c,array<int,6> &a){
	array<int,6> b;
	switch(c){
		case 'F' : b={a[3],a[0],a[2],a[5],a[4],a[1]}; break;
		case 'B' : b={a[1],a[5],a[2],a[0],a[4],a[3]}; break;
		case 'L' : b={a[4],a[1],a[0],a[3],a[5],a[2]}; break;
		case 'R' : b={a[2],a[1],a[5],a[3],a[0],a[4]}; break;
		case 'C' : b={a[0],a[4],a[1],a[2],a[3],a[5]}; break;
		case 'D' : b={a[0],a[2],a[3],a[4],a[1],a[5]}; break;
	}
	a=b;
}
int main(){
	int n; cin >> n;
	string s;
	array<int,6> dic;
	for(int i=0;i<n;i++){
		dic={1,2,3,5,4,6};
		cin >> s;
		for(char c:s) roll(c,dic);
		if(i) cout << " ";
		cout << dic[1];
	}
}
