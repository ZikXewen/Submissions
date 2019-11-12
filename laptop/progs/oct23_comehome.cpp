#include<cstdio>
#include<vector>
#include<queue>
#define ii pair<int,int>
#define MXN 65
using namespace std;
int P,w; char u,v;
bool b[MXN];
vector<ii> ed[MXN];
pair<char,int> dijk(int st){
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.emplace(0,st);
	while(!q.empty()){
		auto x=q.top(); q.pop();
		if(b[x.second]) continue;
		if(x.second<25) return {x.second+'A',x.first};
		b[x.second]=true;
		for(ii i:ed[x.second]) if(!b[i.first]) q.emplace(x.first+i.second,i.first);
	}
}
int main(){
	scanf("%d",&P);
	for(int i=0;i<P;i++){
		scanf(" %c %c %d",&u,&v,&w);
		ed[u-'A'].emplace_back(v-'A',w);
		ed[v-'A'].emplace_back(u-'A',w);
	}
	auto tem=dijk(25);
	printf("%c %d",tem.first,tem.second);
}