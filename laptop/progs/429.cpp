#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
#include<cstring>
using namespace std;
vector<string> v;
vector<int> lst[250];
int chk[250];
int sh(string x){
	for(int i=0;i<v.size();i++) if(!v[i].compare(x)) return i;
	return -1;
}
bool cmp(string a,string b){
	int ct=0;
	if(a.length()!=b.length()) return false;
	for(int cur=0;cur<a.length();cur++)
		if(a[cur]!=b[cur])
			if(++ct==2) return false;
	if(ct==1) return true;
	return false;
}
void ck(string inp){
	for(int i=0;i<v.size();i++){
		if(cmp(inp,v[i])){
			lst[i].push_back(v.size());
			lst[v.size()].push_back(i);
		}
	}
	v.push_back(inp);
}
int bfs(int nx,int ed){
	queue<pair<int,int> > q;
	q.push(make_pair(nx,0)); chk[nx]=1;
	while(!q.empty()){
		auto x=q.front(); q.pop();
		if(x.first==ed) return x.second;
		for(int i:lst[x.first]){
			if(!chk[i]){
				chk[i]=1;
				q.push(make_pair(i,x.second+1));
			}
		}
	}
}
int main(){
//	freopen("file.txt","w",stdout);
	string t,e,l;
	int c,ct=0;
	cin >> c;
	while(ct++!=c){
		if(ct!=1) cout << endl;
		while(cin >> t){
			if(!t.compare("*")) break;
			ck(t);
		}
		getline(cin,l);
		while(getline(cin,l) && l!=""){
			memset(chk,0,sizeof(chk));
			istringstream strm(l);
			strm >> t >> e;
			cout << l << " " << bfs(sh(t),sh(e)) << endl;
		}
	}
//	fclose(stdout);
}
