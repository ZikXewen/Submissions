#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v;
char spec;
int flood(int p,int q){
	if(p==v.size()||p==-1) return 0;
	if(v[p][q]==spec){
		v[p][q]='\0';
		return flood(p+1,q) + flood(p,(q+1)%v[0].length()) + flood(p-1,q) + flood(p,(v[0].length()+q-1)%v[0].length()) + 1;
	}
	return 0;
}
int find_max(){
	int mx=0;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].length();j++){
			mx=max(mx,flood(i,j));
		}
	}
	return mx;
}
int main(){
	//freopen("file.txt","w",stdout);
	int m,n;
	while(cin >> m >> n){
		v.clear();
		for(int i=0;i<m;i++){
			string t;
			cin >> t;
			v.push_back(t); 
		}
		cin >> m >> n; spec=v[m][n];
		flood(m,n);
		cout << find_max() << endl;
	}
	//fclose(stdout);
}
