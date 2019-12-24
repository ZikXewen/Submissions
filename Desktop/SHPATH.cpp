#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define MXN 10005
#define ii pair<int,int>
using namespace std;
int T,N,P,NR,W,R;
bool vst[MXN];
char S[13],S1[13],S2[13];
map<string,int> m;
vector<ii> v[MXN];
int dijk(int s,int e){// cout << s << ' ' << e << ' ';
	priority_queue<ii,vector<ii>,greater<ii>> q;
	memset(vst,0,sizeof vst);
	q.push({0,s});
	while(!q.empty()){
		ii x=q.top(); q.pop();
		if(vst[x.second]) continue;
		if(x.second==e) return x.first;
		vst[x.second]=true;
		for(ii i:v[x.second]) if(!vst[i.first]) q.push({x.first+i.second,i.first});
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T; while(T--){
		cin >> N;
		m.clear();
		for(int i=1;i<=N;i++) v[i].clear();
		for(int i=1;i<=N;i++){
			cin >> S >> P; m[S]=i;
			while(P--){
				cin >> NR >> W;
				v[i].push_back({NR,W});
				v[NR].push_back({i,W});
			}
		}
		cin >> R; while(R--){
			cin >> S1 >> S2;
			cout << dijk(m[S1],m[S2]) << '\n';
		}
	}
}
