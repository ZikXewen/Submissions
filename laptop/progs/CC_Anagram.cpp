#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s,s2;
int H[27],N[27];
bool ck(const int a[27],const int b[27]){
	for(int i=0;i<26;i++) if(a[i]!=b[i]) return false;
	return true;
}
bool fd(int len){
	memset(H,0,sizeof H);
	for(int j=0;j<len;j++) H[s[j]-'A']++;
	for(int i=0;i<=s.length()-len;i++){
		memset(N,0,sizeof N);
		for(int j=0;j<len;j++) N[s2[j]-'A']++;
		if(ck(H,N)) return true;
		for(int j=0;j<s2.length()-len;j++){
			N[s2[j]-'A']--; N[s2[j+len]-'A']++;
			if(ck(H,N)) return true;
		}
		if(i==s.length()-len) continue;
		H[s[i]-'A']--; H[s[i+len]-'A']++;
	}
	return false;
}
int bins(int s,int e){
	if(s>e) return e;
	int md=(s+e)/2;
	if(fd(md)) return bins(md+1,e);
	return bins(s,md-1);
}
int main(){
	cin >> s >> s2;
	cout << bins(1,min(s.length(),s2.length()));
}
