#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
vector<pair<int,int>> v;
map<vector<pair<int,int>>,int> m;
int T,Q,N,x,y;
int main(){
	scanf("%d%d",&T,&Q);
	while(T--){
		v.clear();
		scanf("%d",&N);
		while(--N){
			scanf("%d%d",&x,&y);
			v.emplace_back(min(x,y),max(x,y));
		}
		sort(v.begin(),v.end());
		m[v]++;
	}
	while(Q--){
		v.clear();
		scanf("%d",&N);
		while(--N){
			scanf("%d%d",&x,&y);
			v.emplace_back(min(x,y),max(x,y));
		}
		sort(v.begin(),v.end());
		printf("%d\n",m[v]);
	}
}
