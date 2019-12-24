#include<cstdio>
#define MXN 200005
using namespace std;
int v[MXN],t[MXN],T,N;
long long mrgs(int s,int e){
	if(s==e) return 0;
	int m=(s+e)>>1 ,i=s,j=m+1,k=s;
	long long ret=mrgs(s,m)+mrgs(m+1,e);
	while(i<=m&&j<=e){
		if(v[i]<=v[j]) t[k++]=v[i++];
		else{
			t[k++]=v[j++];
			ret+=m-i+1;
		}
	}
	while(i<=m) t[k++]=v[i++];
	while(--k>=s) v[k]=t[k];
	return ret;
}
int main(){
	scanf("%d",&T); while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&v[i]);
		printf("%lld\n",mrgs(1,N));
	}
}
