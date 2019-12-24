#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> v[2500];
int ck[2500];
void bfs(int k){
	int ct=0,cur=0,mx=0,md;
	queue<pair<int,int> > q;
	q.push(make_pair(k,0));
	ck[k]=1;
	while(!q.empty()){
		auto x=q.front(); q.pop();
		if(x.second!=cur){
			if(ct>mx){
				mx=ct;
				md=cur;
			}
			cur++;
			ct=0;
		}
		if(cur) ct++;
		for(int i:v[x.first]){
			if(!ck[i]){
				ck[i]=1;
				q.push(make_pair(i,cur+1));
			}
		}	
	}
	if(ct>mx){
		mx=ct;
		md=cur;
	}
	if(!md||!mx) cout << "0" << endl;
	else cout << mx << " " << md << endl;
		
}
int main(){
	int n,t; cin >> n;
	for(int i=0;i<n;i++){
		int m; cin >> m;
		for(int j=0;j<m;j++){
			int k; cin >> k;
			v[i].push_back(k);
		}
	}
	cin >> t;
	while(t--){
		memset(ck,0,sizeof(ck));
		int c; cin >> c;
		bfs(c);
	}
}
