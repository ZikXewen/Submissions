#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int h[200000],p[200000],m;
vector<pair<int,pair<int,int> > > v;
int fd(int x){
	if(x==p[x]) return x;
	return fd(p[x]);
}
bool un(int u,int v){
	int pu=fd(u),pv=fd(v);
	if(pu==pv) return false;
	if(h[pu]==h[pv]){
		p[pv]=pu;
		h[pu]++;
		return true;
	}
	if(h[pu]<h[pv]){
		p[pu]=pv;
		return true;
	}
	p[pv]=pu;
	return true;
}
int main(){
	int n;
	while(cin >> m >> n && m && n){
		v.clear();
		memset(h,1,sizeof(h));
		int ct=0;
		long long sm=0;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			sm+=z;
			v.push_back(make_pair(z,make_pair(x,y)));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<m;i++) p[i]=i;
		for(auto x=v.begin();x!=v.end();x++){
			if(un(x->second.first,x->second.second)){
				sm-=x->first;
			}
		}
		cout << sm << endl;
	}
}
