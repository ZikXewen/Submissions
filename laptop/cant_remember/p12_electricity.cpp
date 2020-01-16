#include<cstdio>
#include<queue>
#define ii pair<int,int>
#define MXN 500005
using namespace std;
int N,K,rev[MXN],ans[MXN];
void dp(){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({rev[1],1});
    for(int i=2;i<=N;i++){
        while(i-pq.top().second>K) pq.pop();
        ans[i] = (pq.top().first)+rev[i];
        pq.push({ans[i],i});
    }
}
int main(){
    ans[0]=-999999;
	scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) scanf("%d",&rev[i]);
    dp();
    printf("%d",ans[N]);
}
