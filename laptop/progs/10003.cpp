#include<iostream>
#include <vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> v;
int ck[1000][1000];
int dp(int s,int e){
	if(ck[s][e]!=-1) return ck[s][e];
	int mn=2147483646;
	if(e-s==1) return 0;
	for(int i=s+1;i<e;i++){
		mn=min(mn,dp(s,i)+dp(i,e));
	}
	return ck[s][e] = mn+v[e]-v[s];
}
int main(){
	freopen("file.txt","w",stdout);
	int m;
	while(cin >> m && m){
		memset(ck,-1,sizeof(ck));
		int n;
		v.clear();
		v.push_back(0);
		cin >> n;
		for(int i=0;i<n;i++){
			int t;
			cin >> t;
			v.push_back(t);
		}
		v.push_back(m);
		cout << "The minimum cutting is " << dp(0,n+1) << "." << endl;
	}
	fclose(stdout);
}
