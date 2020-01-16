#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int lrg;
string s;
vector<char> v;
vector<int> val;
void chk(){
	for(char c:s){
		auto it = find(v.begin(),v.end(),c);
		if(it!=v.end()) lrg+=val[it-v.begin()];
	}
}
int main(){
	//freopen("file.txt","w",stdout);
	int cas; cin >> cas;
	while(cas--){
		v.clear(); val.clear();
		int n,l;
		lrg=0;
		cin >> n;
		for(int i=0;i<n;i++){
			char c; int k;
			cin >> c >> k;
			v.push_back(c);
			val.push_back(k);
		}
		cin >> l;
		getchar();
		while(l--){
			getline(cin,s);
			chk();
		}
		cout << setprecision(2) << fixed << double(lrg)/100 << "$" << endl;
	}
	//fclose(stdout);
}
