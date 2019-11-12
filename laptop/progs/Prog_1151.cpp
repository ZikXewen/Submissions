#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int lis(){
	vector<int> ans={v[0]};
	for(int i=1;i<v.size();i++){
		auto it=lower_bound(ans.begin(),ans.end(),v[i]);
		if(it==ans.end()) ans.push_back(v[i]);
		else *it=v[i];
	}
	return ans.size();
}
int main(){
	int c; scanf("%d",&c); while(c--){
		int t; scanf("%d",&t); v.push_back(t);
	}
	printf("%d",lis());
}
