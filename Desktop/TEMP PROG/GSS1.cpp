#include<cstdio>
#include<algorithm>
#define INF 1<<30
#define MXN 100005
#define MXL 800010
using namespace std;
class ii{
	public:
	long long mx,lt,rt,sm;
};
int N,M,v[MXN],l,r;
ii st[MXL];
ii mrg(ii L,ii R){
	ii ret;
	ret.mx = max( L.rt + R.lt , max( R.mx , L.mx ) );
	ret.lt = max( L.lt , L.sm + R.lt );
	ret.rt = max( R.rt , R.sm + L.rt);
	ret.sm = L.sm + R.sm;
	return ret;
}
void bd(int s,int e,int idx){
	if(s==e){
		st[idx].mx = st[idx].lt = st[idx].rt = st[idx].sm = v[s];
		return;
	}
	int m=(s+e)>>1;
	bd(s,m,idx<<1);
	bd(m+1,e,idx<<1|1);
	st[idx] = mrg(st[idx<<1],st[idx<<1|1]);
}
ii qr(int s,int e,int idx){
	if(r<s || l>e || s>e) return {-INF,-INF,-INF,-INF};
	if(s>=l&&e<=r) return st[idx];
	int m=(s+e)>>1;
	return mrg(qr(s,m,idx<<1),qr(m+1,e,idx<<1|1));
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	bd(1,N,1);
	scanf("%d",&M);
	while(M--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",qr(1,N,1).mx);
	}
}
