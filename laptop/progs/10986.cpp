#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int,int> > v[20001];//Weight,Tail
int sr(int st,int ed){
	bool visit[20001]={};
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,st)); //SumWeight,Tail
	while(!q.empty()){
		auto x=q.top(); q.pop();
		if(x.second==ed) return x.first;
		if(visit[x.second]) continue;
		visit[x.second]=true;
		for(auto i:v[x.second]){
			if(visit[i.second]) continue;
			q.push(make_pair(x.first+i.first,i.second));
		}
	}
	return 1;
}
int main(){

	int c; cin >> c;
	for(int z=1;z<=c;z++){
		int n,m,s,t; cin >> n >> m >> s >> t; //Com,Cable,Start,End
		for(int i=0;i<n;i++) {
			v[i].clear();
		}
		for(int i=0;i<m;i++){
			int p,q,j; cin >> p >> q >> j; //Head,Tail,Weight
			v[p].push_back(make_pair(-j,q)); //Weight,Tail
			v[q].push_back(make_pair(-j,p));
		}
		cout << "Case #" << z << ": " ;
		int tp=-sr(s,t);
		if(tp!=-1) cout << tp << endl;
		else cout << "unreachable" << endl;
	}

	return 0;
}
