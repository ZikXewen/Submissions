#include<cstdio>
#include<list>
#include<algorithm>
#define MXN 1005
using namespace std;
bool b[MXN];
int N,S,M,v[MXN],q,lft;
list<int> cur;
int main(){
	scanf("%d%d%d",&N,&S,&M);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	while(S--){
		scanf("%d",&q);
		auto it=find(cur.begin(),cur.end(),q);
		if(it!=cur.end()) cur.erase(it);
		else{
			lft+=v[q];
			while(lft>M){
				lft-=v[cur.front()];
				cur.pop_front();
			}
		}
		cur.push_back(q);
	}
	printf("%d",M-lft);
}
