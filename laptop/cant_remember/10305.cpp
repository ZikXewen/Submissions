#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
int n,m;
bool ck[101];
stack<int> stk;
vector<int> v[101];
void dfs(int cur){
	if(ck[cur]) return;
	for(int i:v[cur]) dfs(i);
	ck[cur]=true;
	stk.push(cur);
}
int main(){
	while(cin >> n >> m &&(n||m)){
		memset(ck,false,sizeof(ck));
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=0;i<m;i++){
			int p,q;
			cin >> p >> q;
			v[p].push_back(q);
		}
		for(int i=1;i<=n;i++) dfs(i);
		while(!stk.empty()){
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << endl;
	}
}
