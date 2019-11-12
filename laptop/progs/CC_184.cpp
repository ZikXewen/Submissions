#include<cstdio>
#include<algorithm>
#include<vector>
#define MX 1003
using namespace std;
class edge{
	public:
		int w,u,v;
};
bool comp(const edge &L,const edge &R){
	return L.w<R.w;
}
int a,ct=0,n;
vector<int> B(1,0);
vector<edge> E;
int h[MX],p[MX];
void Input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		E.push_back({a,0,i});
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		B.push_back(a);
		for(int j=1;j<i;j++) E.push_back({B[i]+B[j],i,j});
	}
	sort(E.begin(),E.end(),comp);
}
int fd(int x){
	if(p[x]==x) return x;
	return fd(p[x]);
}
bool un(int st,int ed){
	int uw=fd(st),uv=fd(ed);
	if(uw==uv) return false;
	if(h[uw]==h[uv]){
		p[uw]=uv;
		h[uv]++;
		return true;
	}
	if(h[uw]>h[uv]){
		p[uv]=uw;
		return true;
	}
	p[uw]=uv;
	return true;
}
long long Kruskal(){
	long long ret=0;
	for(int i=0;i<=n;i++) p[i]=i;
	for(edge i:E){
		if(un(i.u,i.v)){
			ret+=i.w;
			if(++ct==n) return ret;
		}
	}
}
int main(){
	Input();
	printf("%lld",Kruskal());
}
