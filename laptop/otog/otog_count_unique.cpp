#include<cstdio>
#include<vector>
#include<algorithm>
#define MXN 2000005
using namespace std;
class ii{
	public:
		int st,ed,no;
};
bool comp(ii L,ii R){
	return L.ed<R.ed;
}
int N,Q,a,b,c,v[MXN],ans[MXN],lst[MXN],ft[MXN];
vector<ii> qs;
void ud(int idx,int x){
	for(;idx<=N;idx+=-idx&idx) ft[idx]+=x;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	for(int i=0;i<Q;i++){
		scanf("%d%d",&a,&b); qs.push_back({a,b,i});
	}
	sort(qs.begin(),qs.end(),comp);
	auto rn=qs.begin();
	for(int i=1;i<=N;i++){
		if(lst[v[i]]) ud(lst[v[i]],-1);
		ud(i,1); lst[v[i]]=i;
		while(rn!=qs.end()&&rn->ed==i){
			ans[rn->no]=qr(rn->ed)-qr(rn->st-1); rn++;
		}
	}
	for(int i=0;i<Q;i++) printf("%d\n",ans[i]);
} 
