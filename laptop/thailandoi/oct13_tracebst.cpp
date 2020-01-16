#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int N,ct;
map<string,int> m;
string s[100005];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> s[i]; *(s[i].end()-1)='O';
		if(!m[s[i]]) m[s[i]]=0;
	}
	for(auto &i:m) i.second=++ct;
	for(int i=0;i<N;i++) cout << m[s[i]] << '\n';
}
