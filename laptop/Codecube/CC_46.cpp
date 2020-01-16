#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
class trip{
	public:
		bool typ;
		int st,ed;
};
int N,Q,S,E,tem,ft[200005];
bool CMD;
vector<trip> qs;
vector<int> cpy={0};
void mk(int s,int e){
	s=find(cpy.begin(),cpy.end(),s)-cpy.begin();
	e=find(cpy.begin(),cpy.end(),e)-cpy.begin();
	for(;s<=N;s+=-s&s) ft[s]++;
	for(;e<=N;e+=-e&e) ft[e]--;
}
int qr(int ind){
	int ret=0;
	ind=upper_bound(cpy.begin(),cpy.end(),ind)-cpy.begin()-1;
	if(ind==0) return 0;
	for(;ind>0;ind-=-ind&ind) ret+=ft[ind];
	return ret;
}
int main(){
	scanf("%d%d",&N,&Q);
	while(Q--){
		cin >> CMD;
		if(CMD){
			scanf("%d%d",&S,&E);
			cpy.push_back(S); cpy.push_back(++E);
		}
		else scanf("%d",&S);
		qs.push_back({CMD,S,E});
	}
	sort(cpy.begin(),cpy.end());
	cpy.erase(unique(cpy.begin(),cpy.end()),cpy.end());
	for(auto i:qs){ 
		if(i.typ) mk(i.st,i.ed);
		else{
			tem=qr(i.st);
			if(tem%6==0) printf("sleep\n");
			else if(tem%2) printf("eat\n");
			else printf("work\n");
		}
	}
}
