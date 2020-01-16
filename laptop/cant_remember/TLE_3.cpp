#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using ii=pair<int,int>
int N,M,_u,_v,_w;
vector<ii> ed;
void Input(){
	cin >> N >> M;
	while(M--){
		cin >> _u >> _v >> _w;
		ed[_u].push_back({_v,_w});
		ed[_v].push_back({_u,_w});
	}
}
void Serv(){
	
}
int main(){
	Input();
	Serv();
}
