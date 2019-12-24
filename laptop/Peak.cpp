#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a,b,n,m; bool pre,ard[1000000002];
vector<int> v;
int main(){
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&a);
		if(a<b&&pre&&!ard[b]){
			ard[b]=true; v.push_back(b);
		}
		pre=a>b; b=a;
	}
	if(pre&&!ard[b]) v.push_back(b);
	auto it=v.end();
	sort(v.begin(),v.end());
	if(v.empty()) printf("-1");
	else if(v.size()<m) for(int i:v) printf("%d\n",i);
	else while (m--) printf("%d\n",*--it);
}
