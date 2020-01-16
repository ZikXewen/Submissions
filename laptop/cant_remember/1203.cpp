#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,pair<int,int> > > q={}; //Current , Key , Initial
int main(){
	//freopen("file.txt","w",stdout);
	string s; int n,m,k;
	while(cin >> s){
		if(s=="#") break;
		cin >> n >> m; //Key , Value
		q.push(make_pair(-m,make_pair(-n,-m)));
	}
	cin >> k; while(k--){
		auto x=q.top(); q.pop();
		cout << -x.second.first << endl;
		q.push(make_pair(x.first+x.second.second,x.second));
	}
	//fclose(stdout);
}
