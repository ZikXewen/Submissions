#include<iostream>
#include<vector>
#include<cstring>
#include<array>
using namespace std;
vector<int> v[102];
int mx,n;
bool mrk[102],ans[102],prt;
bool ck(int pt){
	for(auto x=v[pt].begin();x!=v[pt].end();x++){
		if(mrk[*x]) return false;
	}
	return true;
}
void bt(int cur,int ct){
	if(cur==n+1){
		if(ct>=mx){
			mx=ct;
			copy(begin(mrk),end(mrk),begin(ans));
		}
		return;
	}
	if(ck(cur)){
		mrk[cur]=1;
		bt(cur+1,ct+1);
		mrk[cur]=0;
	}
	bt(cur+1,ct);
}
int main(){
	freopen("file.txt","w",stdout);
	int c; cin >> c;
	while(c--){
		mx=0;
		memset(mrk,false,sizeof(mrk));
		for(int i=0;i<102;i++)v[i].clear();
		int m,z=1; cin >> n >> m;
		for(int i=0;i<m;i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bt(1,0);
		cout << mx << endl;
		for(z=1;ans[z]!=true;z++);
		cout << z;
		for(++z;z<=n;z++) if(ans[z]==true) cout << " " << z;
		cout << endl;
	}
	fclose(stdout);
}
