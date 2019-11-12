#include <cstdio>
#include <algorithm>
using namespace std;
class ii{public: int sm,l,r,mx;};
const int MXN = 200005;
const int INF = 2e9;
int N,M,v[MXN],a,b;
ii st[MXN<<2];
ii mrg(ii L,ii R){
	ii ret;
	ret.sm=L.sm+R.sm;
	ret.l=max(L.l,L.sm+R.l);
	ret.r=max(R.r,L.r+R.sm);
	ret.mx=max(max(L.mx,R.mx),L.r+R.l);
	return ret;
}
void bd(int s,int e,int idx){
	if(s==e) {st[idx]={v[s],v[s],v[s],v[s]}; return;}
	int m=(s+e)>>1;
	bd(s,m,idx<<1); bd(m+1,e,idx<<1|1);
	st[idx]=mrg(st[idx<<1],st[idx<<1|1]);
}
ii qr(int s,int e,int idx){
	if(b<s||a>e) return {0,0,0,0};
	if(s>=a&&e<=b) return st[idx];
	int m=(s+e)>>1;
	return mrg(qr(s,m,idx<<1),qr(m+1,e,idx<<1|1));
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	bd(1,MXN,1);
	while(M--) {scanf("%d%d",&a,&b); a++; b++;printf("%d\n",qr(1,MXN,1).mx);}
}
