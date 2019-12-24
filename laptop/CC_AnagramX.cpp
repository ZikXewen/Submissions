#include<iostream>
#include<algorithm>
using namespace std;
string s,s2;
int Ana(){
	vector<vector<int> > v;
	for(int len=min(s.length(),s2.length());len>0;len--){
		v.clear();
		vector<int> tem(26,0),needle(26,0);
		for(int i=0;i<len;i++){
			tem[s[i]-'A']++;
			needle[s2[i]-'A']++;
		}
		
		v.push_back(tem);
		for(int i=0;i<s.length()-len;i++){
			tem[s[i]-'A']--; tem[s[i+len]-'A']++;
			v.push_back(tem);
		}
		sort(v.begin(),v.end());
		
		if(binary_search(v.begin(),v.end(),needle)) return len;
		for(int i=0;i<s2.length()-len;i++){
			needle[s2[i]-'A']--; needle[s2[i+len]-'A']++;
			if(binary_search(v.begin(),v.end(),needle)) return len;
		}
	}
	return -1;
}
int main(){
	cin >> s >> s2;
	cout << Ana();
}
