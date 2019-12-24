#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,p[10001],h[10001];
int fd(int x){
	if(p[x]==x) return x;
	return fd(p[x]);
}
bool un(int u,int w){
	int pu=fd(u),pw=fd(w);
	if(pu==pw) return false;
	if(h[pu]==h[pw]){
		p[pu]=pw;
		h[pw]++;
		return true;
	}
	if(h[pu]>h[pw]){
		p[pw]=pu;
		return true;
	}
	p[pu]=pw;
	return true;
}
int main(){
	int cs; cin >> cs;
	vector<pair<int,pair<int,int> > > v;
	while(cs--){
		int ans=0;
		v.clear();
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			p[i]=i; h[i]=0;
		}
		for(int i=0;i<m;i++){
			int u,y,w; cin >> u >> y >> w;
			v.push_back(make_pair(w,make_pair(u,y)));
		}
		sort(v.begin(),v.end());
		for(int i=v.size()-1;i>=0;i--){
			if(!un(v[i].second.first,v[i].second.second)){
				ans+=v[i].first;
			}
		}
		cout << ans << endl;
	} getchar();getchar();
}
