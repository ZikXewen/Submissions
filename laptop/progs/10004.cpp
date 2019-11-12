#include<iostream>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
set<int> v[200];
int ck[200];
void bfs(){
	queue<pair<int,int> > q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		auto x=q.front(); q.pop();
		ck[x.first]=x.second;
		for(int i:v[x.first]){
			if(ck[i]){
				if(x.second==ck[i]){
					cout << "NOT BICOLORABLE." << endl;
					return;
				} 
			}
			else{
				q.push(make_pair(i,(x.second*2)%3));
			}
		}
	}
	cout  << "BICOLORABLE." << endl;
}
int main(){
	int n,m;
	while(cin >> n && n){
		memset(ck,0,sizeof(ck));
		cin >> m;
		for(int i=0;i<m;i++){
			int p,q;
			cin >> p >> q;
			v[p].insert(q); v[q].insert(p);
		}
		bfs();
		for(int i=0;i<n;i++){
			v[i].clear();
		}
	}
}
