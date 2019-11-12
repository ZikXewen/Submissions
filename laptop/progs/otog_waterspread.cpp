#include<cstdio>
#include<queue>
#define ii pair<int,int>
#define iib pair<ii,bool>
using namespace std;
int n,m,q,a,b,ind,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ct[1000001]={1};
bool vst[1001][1001];
bool val(int x,int y){
	if(x<=0||y<=0||x>n||y>n) return false;
	return true;
}
void flood(int sx,int sy){
	queue<iib> q;
	bool f=true; ind=0;
	q.push(iib(ii(sx,sy),false)); vst[sx][sy]=true;
	while(!q.empty()){
		if(f!=q.front().second){
			ct[ind+1]=ct[ind++]; f=!f;
		}
		int x=q.front().first.first,y=q.front().first.second; q.pop();
		for(int i=0;i<4;i++){
			if(val(x+dx[i],y+dy[i])&&!vst[x+dx[i]][y+dy[i]]){
				vst[x+dx[i]][y+dy[i]]=true; ct[ind]++;
				q.push(iib(ii(x+dx[i],y+dy[i]),!f));
			}
		}
	}
}
int main(){
	//freopen("inp.txt","r",stdin);
	//freopen("file.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		vst[a][b]=true;
	}
	scanf("%d%d",&a,&b);flood(a,b);
	while(q--){
		scanf("%d",&a);
		if(a>ind) printf("%d\n",ct[ind]);
		else printf("%d\n",ct[a]);
	}
	//fclose(stdin);
	//fclose(stdout);
}
