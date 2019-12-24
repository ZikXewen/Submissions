#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MXN 100005
using namespace std;
vector<int> v[MXN];
int N,M,col[MXN],K,x,y;
bool chk(int st){
	col[st]=1;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int k=q.front(); q.pop();
		for(int i:v[k]){
			if(i==k) return false;
			if(col[i]==col[k]) return false;
			if(col[i]==-1) {col[i]=1-col[k]; q.push(i);}
		}
	}
	return true;
}
int main(){
	scanf("%d",&K); while(K--){
		bool b=true;
		memset(col,-1,sizeof col);
		scanf("%d%d",&N,&M);
		for(int i=0;i<=N;i++) v[i].clear();
		for(int i=0;i<M;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y); v[y].push_back(x);
		}
		for(int i=1;i<=N;i++) if(col[i]==-1&&!chk(i)) {
			printf("no\n"); b=false; break;
		}
		if(b) printf("yes\n");
	}
}
