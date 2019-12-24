#include<iostream>
#include<vector>
#include<string>
using namespace std;
string H,N; vector<int> mrk(260),nee(260); int ct=0;
int main(){
	getline(cin,H); getline(cin,N);
	for(int i=0;i<N.length();i++){
		mrk[int(H[i])]++;
		nee[int(N[i])]++;
	}
	//for(int i:mrk) cout << i << ' ';
	if(mrk==nee) ct++;
	for(int i=0;i<H.length()-N.length();i++){
		mrk[int(H[i])]--;
		mrk[int(H[i+N.length()])]++;
		if(mrk==nee) ct++;
	}
	cout << ct;
}
