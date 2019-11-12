#include<iostream>
#include<string>
using namespace std;
string s;
bool b[1000005],cur;
int ct;
int main(){
	cin >> s;
	for(int i=0;i<s.length();i++) if(s[i]>='A'&&s[i]<='Z') b[i]=1;
	if(b[0]) ct++;
	for(int i=1;i<s.length();i++){
		if(b[i]==!cur){
			if(b[i-1]==!cur) cur=!cur;
			else ct++;
		}
	}
	cout << ct;
}
