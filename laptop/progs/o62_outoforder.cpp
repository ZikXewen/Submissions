#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MXN = 1e5+5;
int N,h[MXN],d[MXN],v[MXN],ft[MXN],ans;
bool comp(const int &L, const int &R){return h[L]>h[R];}
void inp(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&h[i]);
	for(int i=1;i<=N;i++) scanf("%d",&d[i]);
	for(int i=0;i<N;i++) v[i]=i+1;
}
void ud(int x){
	for(;x<=N;x+=-x&x) ft[x]++;
}
int qr(int x){
	int ret=0; for(;x;x-=-x&x) ret+=ft[x];
	return ret;
}
void fw1(){
	sort(v,v+N,comp);
	for(int i=0;i<N;i++) {
		ans+=qr(v[i])-qr(max(0LL,v[i]-d[v[i]]-1));
		ud(v[i]);
	}
}
void fw2(){
	reverse(v,v+N);
	for(int i=0;i<N;i++) {
		ans+=qr(min(N,v[i]+d[v[i]]))-qr(v[i]);
		ud(v[i]);
	}
}
main(){
	inp();
	fw1();
	memset(ft,0,sizeof ft);
	fw2();
	cout << ans;
}
