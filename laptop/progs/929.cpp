#include<iostream>
#include<queue>
using namespace std;
int r,c,v[1000][1000];
bool ps[1000][1000];
int sp(){
	priority_queue<pair<int,pair<int,int> > > q; //Weight,Coordinates
	q.push(make_pair(-v[0][0],make_pair(0,0)));
	while(!q.empty()){
		auto x=q.top(); q.pop();
		//cout << x.first << " " << x.second.first << " " << x.second.second << endl;
		if(x.second.first==r-1&&x.second.second==c-1) return x.first;
		if(ps[x.second.first][x.second.second]) continue;
		ps[x.second.first][x.second.second]=true;
		if(x.second.first>0) q.push(make_pair(x.first-v[x.second.first-1][x.second.second],make_pair(x.second.first-1,x.second.second)));
		if(x.second.second>0) q.push(make_pair(x.first-v[x.second.first][x.second.second-1],make_pair(x.second.first,x.second.second-1)));
		if(x.second.first<r-1) q.push(make_pair(x.first-v[x.second.first+1][x.second.second],make_pair(x.second.first+1,x.second.second)));
		if(x.second.second<c-1) q.push(make_pair(x.first-v[x.second.first][x.second.second+1],make_pair(x.second.first,x.second.second+1)));
	}
	return 0;
}
int main(){
	int z; cin >> z;
	while(z--){
		cin >> r >> c;
		for(int i=0;i<r;i++) 
			for(int j=0;j<c;j++){
				cin >> v[i][j];
				ps[i][j]=false;
			}
		cout << -sp() << endl;
	}
}
