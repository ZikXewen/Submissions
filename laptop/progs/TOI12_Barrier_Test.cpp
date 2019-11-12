#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
class item{
public:
	int val,ind,len;
	bool st;
};
int a,n,w;
vector<int> v;
pair<int,int> Barrier(){
	queue<item> q;
	int ret=0,ans;
	q.push({0,0,0,true});
	while(!q.empty()){
		item x=q.front(); q.pop();
		if(x.ind++==n||x.val<0) continue;
		if(x.val>ret){
			ret=x.val; ans=x.len;
		}
		else if(x.val==ret) ans=min(ans,x.len);
		if(x.len>=w){if(x.st) q.push({x.val+v[x.ind]-v[x.ind-w],x.ind,w,x.st});}
		else q.push({x.val+v[x.ind],x.ind,x.len+1,x.st});
		if(v[x.ind]<=0&&x.ind<n-1) q.push({v[x.ind+1],x.ind+1,1,false});
	}
	return {ret,ans};
}
int main(){
	cin >> n >> w;
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	auto x=Barrier();
	cout << x.first << endl << x.second;
}
