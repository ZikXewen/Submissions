#include<bits/stdc++.h>
using namespace std;
int main(){
	string a="1234567890123";
	int ans=0;
	for(int i=0;i<12;i++) ans+=(a[i]-'0')*(13-i);
	ans%=11;
	if(ans<=1) cout << 1-ans;
	else cout << 11-ans;
}