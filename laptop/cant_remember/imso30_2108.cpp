#include <bits/stdc++.h>
using namespace std;
string bin(int x){
	string ret={};
	for(;x;x>>=1) if(x&1) ret+='1'; else ret+='0';
	return ret;
}
int main(){
	int ans=0;
	for(int i=1;i<=10;i++){
		string x=bin(i);
		int ct=0;
		for(auto j:x){
			if(j=='1') {
				ct++; 
				if(ct==3) {ans++; break;}
			}
			else ct=0;
		}
	}
	cout << ans;
}
