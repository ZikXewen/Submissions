#include<cstdio>
#include<queue>
#include<vector>
#define MXN 100000
using namespace std;
int ct,N,M,x,y,ind[MXN];
vector<int> v[MXN],topo;
queue<int> q;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		ind[y]++;
	}
	for(int i=1;i<=N;i++) if(!ind[i]) q.push(i);
	while(!q.empty()){
		int k=q.front(); q.pop();
		topo.push_back(k);
		for(int i:v[k]) if(!--ind[i]) q.push(i);
		ct++;
	}
	if(ct!=N) printf("no");
	else for(int i:topo) printf("%d\n",i);
}
