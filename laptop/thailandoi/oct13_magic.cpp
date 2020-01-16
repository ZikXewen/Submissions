#include<iostream>
#include<queue>
#include<set>
#define INF 1<<30
using namespace std;
class ii{
	public:
		int w,v,d,nw;
	bool operator<(const ii &R) const{
		return w>R.w;
	}
};
class iii{
	public:
		int w,v,d;
	bool operator<(const iii &R) const{
		return d>R.d;
	}
};
int N,M,cmd,t,a,b,d,x;
priority_queue<ii> q;
priority_queue<iii> more;
set<int> vst;
int main(){
	scanf("%d%d",&N,&M); N+=M;
	for(int tim=0;tim<N;){ //printf("\n%d\n",tim);
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d%d%d",&t,&a,&b);
			if(t==1) q.push({a,b,INF,0});
			if(t==2){
				scanf("%d",&d);
				q.push({a,b,d,0});
			}
			if(t==3){
				scanf("%d%d",&d,&x);
				q.push({a,b,d,x});
				more.push({x,b,d});
			}
		}
		else while(true){
			if(q.empty()){printf("0\n"); break;}
			ii x=q.top(); q.pop();
			if(x.d<=tim) continue;
			vst.insert(x.nw);
			printf("%d\n",x.v); break;
		} tim++;
		while(!more.empty()){
			iii x=more.top();
			if(x.d>tim) break;// printf("%d\n\n",tim);
			more.pop();
			if(vst.find(x.w)!=vst.end()) continue;
			q.push({x.w,x.v,INF});
		}
	}
}
