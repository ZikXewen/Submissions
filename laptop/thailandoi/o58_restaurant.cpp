#include <cstdio>
#include <vector>
#include <algorithm>
#define MXN 305
using namespace std;
class ii{
	public: int u,v,w;
	inline bool operator<(const ii&R)const{return w<R.w;}
};
int N,T,a,vec[MXN],p[MXN],mx,an;
vector<ii> ed;
int fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]);
}
bool un(int s,int e){
	int x=fd(s),y=fd(e);
	if(x==y) return false;
	p[x]=y; return true;
}
int main(){
	scanf("%d%d",&N,&T);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){ scanf("%d",&a);	if(i<j) ed.push_back({i,j,a}); }
		p[i]=i;
	}
	sort(ed.begin(), ed.end());
	for(ii i:ed) if(un(i.u,i.v)) vec[i.u]++,vec[i.v]++;
	for(int i=1;i<=N;i++) if(mx<vec[i]) {mx=vec[i]; an=i;}
	printf("%d",an);
	if(T>>1) printf("\n%d",mx);
}
