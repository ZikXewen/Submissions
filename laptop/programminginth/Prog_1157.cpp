#include<cstdio>
#include<queue>
#define MXN 500005
#define ii pair<int,int>
using namespace std;
int N,K,ar[MXN];
bool vst[MXN];
priority_queue<ii> q;
int fx(){
	q.push({-ar[1],1});
	while(!q.empty()){
		ii i=q.top(); q.pop();
		if(vst[i.second]||i.second>N) continue;
		if(i.second==N) return -i.first;
		vst[i.second]=true;
		for(int j=1;j<=K;j++) if(i.second+j<=N&&!vst[i.second+j]) q.push({i.first-ar[i.second+j],i.second+j});
	}
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&ar[i]);
	printf("%d",fx());
}
