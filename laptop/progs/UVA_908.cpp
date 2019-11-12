#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ii pair<int,int>
#define iii pair<int,ii>
using namespace std;
vector<iii> v; int p[1000001],h[1000001];
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
	bool ck=false; int ans,n,a,b,c; while(cin >> n){
		if(ck) {cout << endl;} ck=true;
		ans=0; v.clear(); memset(h,0,sizeof h);
		while(--n){
			cin >> a >> b >> c; ans+=c;
		} cout << ans << endl; ans=0;
		for(int i=0;i<2;i++){
			cin >> n; while(n--){
				cin >> a >> b >> c; v.push_back(iii(c,ii(b,a)));
			}
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=v.size();i++) p[i]=i;
		for(auto i:v) if(un(i.second.first,i.second.second)) ans+=i.first;
		cout << ans << endl;
	}
	//fclose(stdout);
}
