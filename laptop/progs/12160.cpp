#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int l,u,r;
vector<int> v;
queue<pair<int,int> > q; // Current & Count
bool b[10005];
int qu(){
	while(!q.empty()) q.pop();
	q.push(make_pair(l,0));
	while(!q.empty()&&q.front().second<=9999){
		auto x=q.front(); q.pop();
		for(int i:v){
			int k=(x.first+i)%10000;
			if(k==u) return x.second+1;
			if(!b[k]){
				b[k]=true; q.push(make_pair(k,x.second+1));
			}
		}
	} return -1;
}
int main(){
	//freopen("file.txt","w",stdout);
	int cs=0;
	while(cin>>l>>u>>r && (l||u||r)){
		v.clear(); memset(b,false,sizeof(b));
		for(int i=0;i<r;i++){
			int tm; cin >> tm; v.push_back(tm);
		}
		int tem=qu();
		cout << "Case " << ++cs << ": ";
		if(tem!=-1) cout << tem << endl;
		else cout << "Permanently Locked" << endl;
	}
	//fclose(stdout);
}
