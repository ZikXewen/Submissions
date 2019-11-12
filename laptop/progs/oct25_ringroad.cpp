#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MXN 200005
using namespace std;
int N,K,Q,p[MXN],dist[MXN],cyc[MXN],ft[MXN],cmd,a,b,v;
void ud(int idx,int v){
	for(;idx<=K;idx+=-idx&idx) ft[idx]+=v;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int main(){
	scanf("%d%d%d",&N,&K,&Q);
	for(int i=1;i<=K;i++) {scanf("%d",&cyc[i]); ud(i,cyc[i]); p[i]=i;}
	for(int i=K+1;i<=N;i++)	scanf("%d%d",&p[i],&dist[i]);
	for(int i=K+1;i<=N;i++){
		while(p[i]>K){
			dist[i]+=dist[p[i]];
			p[i]=p[p[i]];
		}
	}
	while(Q--){
		scanf("%d%d%d",&cmd,&a,&b);
		if(cmd){
			if(p[a]==p[b]) {printf("%d\n",abs(dist[a]-dist[b])); continue;}
			int tem=qr(max(p[a],p[b])-1)-qr(min(p[a],p[b])-1);
			printf("%d\n",min(tem,qr(K)-tem)+dist[a]+dist[b]);
		}
		else {ud(a,b-cyc[a]); cyc[a]=b;}
	}
}