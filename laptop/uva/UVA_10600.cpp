#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define ii pair<int,int>
#define iii pair<int,ii>
#define MAX 3000000
using namespace std;
int n,m,p[101],h[101]; vector<iii> v; queue<int> ans;
int fd(int x){
	if(p[x]==x) return x;
	return fd(p[x]);
}
bool un(int s,int e){
	int pw=fd(s),pu=fd(e);
	if(pw==pu) return false;
	if(h[pw]==h[pu]){
		p[pu]=pw; h[pw]++; return true;
	}
	if(h[pw]>h[pu]){
		p[pu]=pw; return true;
	}
	p[pw]=pu; return true;
}
int main(){
	//freopen("file.txt","w",stdout);
	int cs; cin >> cs; while(cs--){
		int sm=0,mn=MAX;
		v.clear();
		cin >> n >> m;
		memset(h,0,sizeof h); for(int i=1;i<=n;i++) p[i]=i;
		for(int i=0;i<m;i++){
			int x,y,w; cin >> x >> y >> w;
			v.push_back(iii(w,ii(x,y)));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<m;i++){
			if(un(v[i].second.first,v[i].second.second)) {ans.push(i); sm+=v[i].first;}
		} cout << sm << " ";
		while(!ans.empty()){
			memset(h,0,sizeof h); for(int i=1;i<=n;i++) p[i]=i;
			sm=0; int x=ans.front(); ans.pop(); int ct=0;
			for(int i=0;i<m;i++){
				if(i!=x&&un(v[i].second.first,v[i].second.second)) {sm+=v[i].first;ct++;}
			}
			if(ct==n-1) mn=min(mn,sm);
		}
		cout << mn << endl;
	}
	//fclose(stdout);
}
