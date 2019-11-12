#include<cstdio>
#include<cstring>
#include<algorithm>
#define MXN 30005
#define MXL 1000000
using namespace std;
int N,M,a,b,q,x,v[MXN],st[MXL],lz[MXL];
char s[MXN];
void bd(int s,int e,int idx){
	if(s==e){
		st[idx]=v[s]; return;
	}
	int m=(s+e)>>1;
	bd(s,m,idx<<1);
	bd(m+1,e,idx<<1|1);
	st[idx]=min(st[idx<<1],st[idx<<1|1]);
}
void ud(int s,int e,int idx){
	if(lz[idx]){
		st[idx]+=lz[idx];
		if(s!=e){
			lz[idx<<1]+=lz[idx]; lz[idx<<1|1]+=lz[idx];
		}
		lz[idx]=0;
	}
	if(e<q) return;
	if(s>=q){
		st[idx]+=x;
		if(s!=e){
			lz[idx<<1]+=x; lz[idx<<1|1]+=x;
		}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1); ud(m+1,e,idx<<1|1);
	st[idx]=min(st[idx<<1],st[idx<<1|1]);
}
int qr(){
	if(lz[1]){
		st[1]+=lz[1];
		lz[2]+=lz[1];
		lz[3]+=lz[1];
		lz[1]=0;
	}
	return st[1];
}
int main(){
	//freopen("file.txt","w",stdout);
	for(int T=1;T<=10;T++){
		memset(st,0,sizeof lz);
		memset(st,0,sizeof st);
		memset(v,0,sizeof v);
		scanf("%d",&N);	scanf(" %s",s);
		for(int i=0;i<N;i++)
			if(s[i]=='(') v[i+1]=v[i]+1;
			else v[i+1]=v[i]-1;
		bd(1,N,1);
		scanf("%d",&M);
		printf("Test %d:\n",T);
		while(M--){
			scanf("%d",&q);
			if(q){
				if(s[q-1]=='(') {s[q-1]=')'; x=-2;}
				else {s[q-1]='('; x=2;}
				ud(1,N,1); v[N]+=x;
			}
			else if(qr()<0||v[N])printf("NO\n");
			else printf("YES\n");
		}
	}
	//fclose(stdout);
}
