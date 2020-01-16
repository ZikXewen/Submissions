#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v,ans;
int mn,n,k;
class trip{
	public:
	vector<int> fst;
	int scd;
	int trd;
};
void dfs(int f,int sm,vector<int> o){
	if((n-sm)<mn&&(n-sm>=0)){
		ans=o;
		mn=n-sm;
	}
	for(int i=f+1;i<v.size();i++){
		o.push_back(v[i]);
		dfs(i,sm+v[i],o);
		o.pop_back();
	}
}
void bfs(){
	queue<trip> q={};
	trip o;
	o.fst=;o.scd=0; o.trd=0;
	q.push(o);
	while(q.size()){
		trip x=q.front();
		if(n-x.trd<mn&&n-x.trd>=0){
			ans=x.fst;
			mn=n-x.trd;
		}
		q.pop();
		for(int i=x.scd+1; i<=n&&i<=x.scd+k; i++){
			o.fst=x.fst;
			o.fst.push_back(v[i-1]);
			o.scd=i;
			o.trd=x.trd+v[i-1];
			q.push(o);
			o.fst.clear();
		}
	}
}
int main(){
	while(true){
		v.clear();
		mn=10000;
		ans.clear();
		int j=0;
		cin >> n >> k;
		for(int j=0;j<k;j++){
			int i;
			cin >> i;
			v.push_back(i);
		}
		vector<int> o;
		dfs(-1,0,o);
		//bfs();
		for(int j=0;j<ans.size();j++){
			cout << ans[j] << " ";
		}
		cout << "sum:" << n-mn << "\n";
	}
}
