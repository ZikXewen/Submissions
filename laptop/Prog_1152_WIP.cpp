#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define ii pair<int,int>
#define MXN 1003
using namespace std;
bool ar[2*MXN];
int N,a,ct;
set<int> s;
vector<ii> v;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&a); v.push_back({a,i+j});
		}
	}
	for(int i=1;i<2*N-1;i++) s.insert(-i);
	sort(v.begin(),v.end(),greater<ii>());
	for(auto i=v.begin();!s.empty();i++){
		auto it=s.lower_bound(-(i->second));
		if(it!=s.end()){
			ct+=i->first; s.erase(it);
		}
	}
	printf("%d",ct);
}
