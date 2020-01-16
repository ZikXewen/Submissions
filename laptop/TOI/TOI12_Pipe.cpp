#include<iostream>
#include<cmath>
#include<algorithm>
#define MXN 15005
#define MX 2e9
using namespace std;
typedef pair<int,int> ii;
ii v[MXN];
bool vst[MXN];
int dist[MXN],ret[MXN],ans=0,n,m;
void Input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
		dist[i]=MX;
	}
}
int Edge(int i,int j){
	//cout << i << ' ' << j << ' ' << abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second) << endl;
	return abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
}
void Pipe(){
	for(int i=0;i<n;i++){
		int mn=-1;
		for(int j=0;j<n;j++) if(mn==-1||!vst[j]&&dist[j]<dist[mn]) mn=j;
		ret[i]=dist[mn]; vst[mn]=true;
		for(int j=0;j<n;j++) if(!vst[j]) dist[j]=min(dist[j],Edge(mn,j));
	}
	sort(ret,ret+n);
	//for(int i=0;i<n;i++) cout << ret[i] << endl;
	for(int i=0;i<n-m;i++) ans+=ret[i];
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	Pipe();
}
