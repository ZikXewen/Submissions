#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MXN 100005
#define ii pair<int,int>
using namespace std;
int N,M,x,y,col[MXN];
vector<ii> v[MXN];
bool bip(int st,int x){
	queue<int> q;
	col[st]=1; q.push(st);
	while(!q.empty()){
		int k=q.front(); q.pop();
		for(ii i:v[k]){
			if(i.second>x) break;
			if(col[i.first]==col[k]) return false;
			if(col[i.first]==-1){
				col[i.first]=1-col[k];
				q.push(i.first);
			}
		}
	}
	return true;
}
bool ck(int x){
	memset(col,-1,sizeof col);
	for(int i=1;i<=N;i++) if(col[i]==-1&&!bip(i,x)) return false;
	return true;
}
int bsearch(int s,int e){ 
	if(s>e) return e;
	int m=(s+e)>>1;
	if(ck(m)) return bsearch(m+1,e);
	return bsearch(s,m-1);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		v[x].emplace_back(y,i);
		v[y].emplace_back(x,i);
	}
	printf("%d",bsearch(1,M));
}
