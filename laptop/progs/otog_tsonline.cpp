#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int N,v[50005],a,sm;
multiset<int> s;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&v[i]);
	sort(v,v+N,greater<int>());
	for(int i=0;i<N;i++) {scanf("%d",&a); s.insert(a);}
	for(int i=0;i<N;i++){
		auto it=s.lower_bound(v[i]);
		if(it==s.begin()) break;
		sm+=v[i];
		s.erase(--it);
	}
	printf("%d",sm);
}
