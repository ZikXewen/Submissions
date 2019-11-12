#include<cstdio>
#include<algorithm>
#define MXN 100005
#define MXL 600005
#define INF 1<<30
using namespace std;
class ii{
	public:
		long long mx,lt,rt,sm;
};
int N,M,v[MXN],cmd,p,q;
ii st[MXL];
ii mrg(ii L,ii R){
	ii ret;
	ret.mx=max(L.mx,max(R.mx,L.rt+R.lt));
	ret.lt=max(L.lt,R.lt+L.sm);
	ret.rt=max(R.rt,L.rt+R.sm);
	ret.sm=L.sm+R.sm;
	return ret;
}
void bd(int s,int e,int idx){
	if(s==e){
		st[idx].lt = st[idx].rt = st[idx].mx = st[idx].sm=v[s];
		return;
	}
	int m=(s+e)>>1;
	bd(s,m,idx<<1);
	bd(m+1,e,idx<<1|1);
	st[idx]=mrg(st[idx<<1],st[idx<<1|1]);
}
void ud(int s,int e,int idx){
	if(s==e){
		st[idx].lt=st[idx].rt=st[idx].mx=st[idx].sm=q;
		return;
	}
	int m=(s+e)>>1;
	if(p<=m) ud(s,m,idx<<1);
	else ud(m+1,e,idx<<1|1);
	st[idx]=mrg(st[idx<<1],st[idx<<1|1]);
}
ii qr(int s,int e,int idx){
	if(e<p||s>q) return {-INF,-INF,-INF,-INF};
	if(s>=p&&e<=q) return st[idx];
	int m=(s+e)>>1;
	return mrg(qr(s,m,idx<<1),qr(m+1,e,idx<<1|1));
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	bd(1,N,1);
	scanf("%d",&M); while(M--){
		scanf("%d%d%d",&cmd,&p,&q);
		if(cmd) printf("%lld\n",qr(1,N,1).mx);
		else ud(1,N,1);
	}
}
