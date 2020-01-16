#include<cstdio>
#include<queue>
#define MX 105
using namespace std;
bool vst[MX][MX][1000];
int m,n,a[MX][MX],s;
queue<pair<int,pair<int,int> > > q;
int main(){
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) scanf("%d",&a[i][j]);
    s=(m-1)>>1;
	if(a[s-1][0]) q.push({1,{s-1,0}});
    if(a[s][0]) q.push({1,{s,0}});
    if(a[s+1][0])q.push({1,{s+1,0}});
    vst[s-1][0][1] = vst[s][0][1] = vst[s+1][0][1] = true;
    while(!q.empty()){
        int lv = q.front().first, x = q.front().second.first, y = q.front().second.second;
        q.pop();
        if(x==s && y==n-1){ printf("%d",lv); return 0; }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++){
            if(i==0 && j==0) continue;
            if(!(x&1) && j==-1 && i) continue; // Can't
            if(x&1 && j==1 && i) continue; // Can't
            int ai = x+i,aj = y+j;
            if(ai<0 || ai>=m || aj<0 || aj>=n) continue;
            if(!a[ai][aj]) continue;
            if((lv+1)%a[ai][aj]) continue;
            if(vst[ai][aj][lv+1]) continue;
            vst[ai][aj][lv+1] = true;
            q.push({lv+1,{ai,aj}});
            //cout << ai << ' ' << aj << ' ' << lv+1 << '\n';
        }
    }
}
