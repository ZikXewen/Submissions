#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> vec[201];
int col[201]; // 0 = Unmarked , 1 = Marked , 2 = Unknown
int bfs(int st){
	queue<int> q; int siz=0,mrk=0; q.push(st); col[st]=1;
	while(!q.empty()){
		int x=q.front(); q.pop(); siz++;
		if(col[x]==1) mrk++;
		for(int i:vec[x]){
			if(col[x]==col[i]) return -1;
			if(col[i]==2){
				col[i]=1-col[x];
				q.push(i);
			}
		}
	}
	if(siz==1) return 1;
	return min(mrk,siz-mrk);
}
int main(){
	//freopen("file.txt","w",stdout);
	int t; scanf("%d",&t); while(t--){
		bool pos=true;
		int v,e,ans=0;
		scanf("%d %d",&v,&e);
		for(int i=0;i<v;i++){
			vec[i].clear();
			col[i]=2;
		}
		for(int i=0;i<e;i++){
			int t1,t2; scanf("%d %d",&t1,&t2);
			vec[t1].push_back(t2);
			vec[t2].push_back(t1);
		}
		for(int i=0;i<v;i++){
			if(col[i]==2){
				int x=bfs(i);
				if(x==-1){
					pos=false; break;
				}
				ans+=x;
			}
		}
		if(pos) printf("%d\n",ans);
		else printf("-1\n");
	}
	//fclose(stdout);
}
