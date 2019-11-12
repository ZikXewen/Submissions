#include<iostream>
#include<queue>
using namespace std;
int T,ft[300005];
long long sm;
string s,p;
queue<int> v[30];
void ud(int idx){
	for(;idx<=s.size();idx+=-idx&idx) ft[idx]++;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T >> s >> p;
	for(int i=0;i<s.size();i++) v[s[i]-'a'].push(i+1);
	for(char i:p){
		if(v[i-'a'].empty()){printf("-1"); return 0;}
		int tem=v[i-'a'].front();  v[i-'a'].pop();
		sm+=tem;
		if(T) {sm-=qr(tem); ud(tem);}
	}
	cout << sm;
}
