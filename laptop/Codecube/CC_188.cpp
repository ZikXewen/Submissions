#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n, q, a, b, c;
map<int, vector<int> > m;
void Input(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		m[a].push_back(i);
	}
	while(q--){
		scanf("%d%d%d",&a,&b,&c);
		auto st=m[c].begin(), ed=m[c].end();
	printf("%d\n",upper_bound(st, ed, b)-lower_bound(st, ed, a));
	}
}
int main(){
	Input();
}
