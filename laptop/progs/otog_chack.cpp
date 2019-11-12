#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n,m,b;
char a;
map<char,int> av;
vector<char> out;
vector<vector<char> > ans;
void bk(){
	if(out.size()==n){
		ans.push_back(out); return;
	}
	for(auto it=av.begin();it!=av.end();it++){
		if(it->second){
			it->second--; out.push_back(it->first); bk();
			it->second++; out.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		av[a]=b;
	}
	bk();
	cout << ans.size() << '\n';
	for(vector<char> v:ans){
		for(char i:v) cout << i;
		cout << '\n';
	}
}
