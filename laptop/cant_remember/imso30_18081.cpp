#include<bits/stdc++.h>
using namespace std;
int cnt;
string bin(int i){
	string s;
	for(;i;i>>=1) if(i&1) s+='1'; else s+='0';
	return s;
}
string dec(int i){
	string s;
	for(;i;i/=10) s+=((i%10)+'0');
	return s;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=1;i<=100000;i++){
		bool cur=0;
		string s=bin(i),s2=dec(i);
		for(int j=0,k=s2.length()-1;j<k;j++,k--) {if(s2[j]!=s2[k]) {cur=1; break;}}
		if(!cur) for(int j=0,k=s.length()-1;j<k;j++,k--) {if(s[j]!=s[k]) {cur=1; break;}}
		if(!cur) {cnt++; cout << s << ' ' << s2 << endl;}
	}
	printf("%d",cnt);
}
