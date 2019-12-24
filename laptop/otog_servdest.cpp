#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<list>
#define INF 2e9
#define MXN 510
#define ii pair<int,int>
#define trip pair<int,ii>
using namespace std;
list<ii> ed[MXN];
list<trip> edges;
int n,m,a,b,c,mn=INF;
bool vst[MXN];
void Input(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		ed[a].push_back({c,b});
		ed[b].push_back({c,a});
		edges.push_back({c,{a,b}});
	}
}
void cut(ii x){
	//cout << ed[x.first].front().first << ' ' << ed[x.second] << endl;
	ed[x.first].pop_front();
	ed[x.second].pop_front();
}
void put(trip x){
	ed[x.second.first].push_back({x.first,x.second.second});
	ed[x.second.second].push_back({x.first,x.second.first});
}
int dijkstra(ii s){
	memset(vst,false,sizeof vst);
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push({0,s.first});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(x.second==s.second) return x.first;
		if(vst[x.second]) continue;
		vst[x.second]=true;
		for(ii i:ed[x.second]) if(!vst[i.second]) q.push({x.first+i.first,i.second});
	}
	return INF;
}
void ServDest(){
	for(trip i:edges){ //cout << 'i';
		cut(i.second);
		mn=min(mn,dijkstra(i.second)+i.first);
		put(i);
	}
}
int main(){
	Input();
	ServDest();
	cout << mn;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
