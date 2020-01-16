#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int bt,sb,sg,tem;
multiset<int> G,B;
void battle(){
	while(!G.empty()&&!B.empty()){ 
		vector<pair<bool,int> > v={}; //False=Green True=Blue
		int x=G.size(),y=B.size();
		int sz=min(bt,min(x,y));
		for(int ct=0;ct<sz;ct++){
			if(*G.begin()<*B.begin()){
				v.push_back(make_pair(false,*G.begin()-*B.begin()));
			}
			if(*B.begin()<*G.begin()) {
				v.push_back(make_pair(true,*B.begin()-*G.begin()));
			}
			G.erase(G.begin()); B.erase(B.begin());
		}
		while(!v.empty()){
			if(v.back().first) B.insert(v.back().second);
			else G.insert(v.back().second);
			v.pop_back();
		}
	}
}
int main(){
	int cas; cin >> cas;
	while(cas--){
		G.clear(); B.clear();
		cin >> bt >> sg >> sb;
		for(int i=0;i<sg;i++){
			cin >> tem; G.insert(-tem);
		}
		for(int i=0;i<sb;i++){
			cin >> tem; B.insert(-tem);
		}
		battle();
		if(!G.empty()){
			cout << "green wins\n";
			for(int rn:G) cout << -rn << endl;
		}
		else if(!B.empty()){
			cout << "blue wins\n";
			for(int rn:B) cout << -rn <<endl;
		}
		else cout << "green and blue died\n";
		if(cas) cout << endl;
	}
}
