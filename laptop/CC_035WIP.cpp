#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,v[100005];
multiset<int> s;
vector<int> e[100005];
bool vst[100005];
queue<pair<int,int> > q;
int main(){
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> v[i];
		s.insert(v[i]);
	}
	for(int i=0;i<m;i++){
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	q.push({k,0});
	while(!q.empty()){
		auto x=q.front(); q.pop();
		vst[x]=true;
		if(x.second!=cur){
			cur++;
			ret+=s.front();
			s.erase(s.front());
		}
		for(int i:e[x.first]) if(!vst[i]) q.push({i,cur+1});
	}
}
