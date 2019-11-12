#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,cs=0;
bool prm(int p){
	for(int i=2;i*i<=p;i++) if(p%i == 0) return false;
	return true;
}
void cir(vector<int> v){ //cout << "o";
	if(v.size()==n&&prm(v[n-1]+v[0])){
		for(int x:v){
			cout << x;
			if(x!=v.back()) cout << " ";
		} cout << endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(find(v.begin(),v.end(),i)==v.end()&&prm(v.back()+i)){
			v.push_back(i);
			cir(v);
			v.pop_back();
		}
	}
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> n){
		if(cs) cout << endl;
		vector<int> v={1};
		cout << "Case " << ++cs << ":" << endl;
		cir(v);
	}
	//fclose(stdout);
}
