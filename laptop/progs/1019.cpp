#include<iostream>
#include<string>
using namespace std;
string cmp(string a, string b){
	int mx=0; string ans;
	for(int i=0;i<a.length()-mx;i++){
		for(int j=0;j<b.length()-mx;j++){
			int ct=0;
			while(a[i+ct]==b[j+ct]&&(i+ct<a.length()&&j+ct<b.length())) ct++;
			if(mx<ct){
				mx=ct;
				ans.assign(a,i,ct);
			}
		}
	}
	return ans;
}
int main(){
	string a,b;
	cin >> a >> b;
	cout << cmp(a,b);
}
