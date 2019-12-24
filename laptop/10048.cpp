#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int h[101],p[101];
vector<pair<int,pair<int,int> > > v;
vector<pair<int,int> > ans[101]; //tail,weight
bool ps[101];
int sr(int u,int w){
	queue<pair<int,int> > q;
	q.push(make_pair(u,0));
	while(!q.empty()){
		auto x=q.front(); q.pop();
		//cout << x.first << " " << x.second << endl;
		
		for(auto i:ans[x.first]){
			if(!ps[i.first]) {
				//cout << x.first << " " << i.first << " " << i.second << endl;
				if(i.first==w){
					//cout << x.first << " " << i.first << " " << i.second << endl;
					return max(x.second,i.second);
				}
				q.push(make_pair(i.first,max(x.second,i.second)));
				ps[i.first]=true;
			}
		}
	}
	return -1;
}
int fd(int x){
	if(x==p[x]) return x;
	return fd(p[x]);
}
bool un(int u,int w){
	int pu=fd(u),pw=fd(w);
	if(pu==pw) return false;
	if(h[pu]==h[pw]){
		p[pw]=pu;
		h[pu]++;
		return true;
	}
	if(h[pu]<h[pw]){
		p[pu]=pw;
		return true;
	}
	p[pw]=pu;
	return true;
}
int main(){
	//freopen("file.txt","w",stdout);
	int cas=1,c,s,q;
	while(cin >> c >> s >> q && (c || s || q)){
		if(cas!=1) cout << endl;
		v.clear();
		memset(h,1,sizeof(h));
		for(int i=0;i<=c;i++){
			p[i]=i;
			ans[i].clear();
		}
		for(int i=0;i<s;i++){
			int u,w,d;
			cin >> u >> w >> d;
			v.push_back(make_pair(d,make_pair(u,w)));
		}
		sort(v.begin(),v.end());
		
		//cout << endl;
		
		for(auto x=v.begin();x!=v.end();x++){
			if(un(x->second.first,x->second.second)){
				ans[x->second.first].push_back(make_pair(x->second.second,x->first));
				ans[x->second.second].push_back(make_pair(x->second.first,x->first));
				
			//	cout << x->second.first << " " << x->second.second << " " << x->first << endl;
				
			}
		}
		//if(cas==3)cout << ans[5][0].first << " " << ans[5][0].second;
		cout << "Case #" << cas++ << endl;
		for(int i=0;i<q;i++){
			memset(ps,false,sizeof(ps));
			int u,w;
			cin >> u >> w;
			int z=sr(u,w);
			if(z!=-1) cout <<  z << endl;
			else cout << "no path" << endl;
		}
	}
	//fclose(stdout);
}
