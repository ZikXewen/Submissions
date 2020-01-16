#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v; //Bob's selection each row
int grid[9][9];
int main(){
	//freopen("file.txt","w",stdout);
	int t; cin >> t;
	while(t--){
		v.clear();
		int mn=64000;
		cin >> n;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++){
			cin >> grid[i][j];
		}
		for(int i=0;i<n;i++) v.push_back(i);
		do{
			int sm=0;
			for(int i=0;i<n;i++) sm+=grid[i][v[i]];
			mn=min(sm,mn);
		}while(next_permutation(v.begin(),v.end()));
		cout << mn << endl;
	}
	//fclose(stdout);
}
