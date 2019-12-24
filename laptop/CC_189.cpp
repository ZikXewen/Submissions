#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ii pair<int,int>
#define MX 100010
#define INF 2e9
using namespace std;
int n,m,s,e,a,b,c,disx[MX],disy[MX],sm=0,mn=INF;
bool vst[MX];
vector<ii> v[MX],ed;
void Dijkstra(int sc,int arr[MX]){
	memset(vst,false,sizeof vst);
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push({0,sc});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(vst[x.second]) continue;
		vst[x.second]=true; arr[x.second]=x.first;
		for(ii i:v[x.second]) if(!vst[i.second]) q.push({i.first+x.first,i.second});
	}
}
void Input(){
	cin >> n >> m >> s >> e;
	while(m--){
		cin >> a >> b >> c;
		v[a].push_back({c,b});
		v[b].push_back({c,a});
		ed.push_back({a,b});
		sm+=c;
	}
}
int main(){
	Input();
	Dijkstra(s,disx);
	Dijkstra(e,disy);
	for(ii i:ed) mn=min(mn,min(disx[i.first]+disy[i.second],disy[i.first]+disx[i.second]));
	cout << sm-mn;
}
