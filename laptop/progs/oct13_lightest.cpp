#include<cstdio>
#include<queue>
#define ii pair<int,int>
using namespace std;
int N,M,a,b;
char cmd;
priority_queue<ii,vector<ii>,greater<ii>> q;
int main(){
	scanf("%d%d",&N,&M); N+=M;
	while(N--){
		scanf(" %c",&cmd);
		if(cmd=='T'){
			scanf("%d%d",&a,&b);
			q.push({a,b});
		}
		else{
			if(!q.empty()){
				printf("%d\n",q.top().second); q.pop();
			}
			else printf("0\n");
		}
	}
}
