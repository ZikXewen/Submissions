#include <bits/stdc++.h>
using namespace std;
class ii {public:int f,s; 
	bool operator<(const ii &R)const{return f<R.f;}
};
const int MXV = 2e4+5;
int V,W,ct;
int p[MXV],mp[MXV],go[MXV],in[MXV];
bool head[MXV];
bool exst[MXV][MXV];
vector<ii> ed;
vector<int> ans,gps[MXV],red[MXV];
int fd(int u){
	if(p[u]==u) return u;
	return p[u]=fd(p[u]);
}
void un(int u,int v){
	int pu=fd(u),pv=fd(v); 
	if(pu==pv) return; 
	p[pu]=pv; head[pu]=1;
}
void bind(int A,int B,int C){
	un(A,B); if(B!=C) un(A,C);
}
void inp(){
	int T,A,B,C;
	scanf("%d%d",&V,&W);
	for(int i=1;i<=V;i++) p[i]=i;
	for(int i=0;i<W;i++){
		scanf("%d%d%d%d",&T,&A,&B,&C);
		if(T==1) {
			if(!exst[A][B]++) ed.push_back({A,B}); 
			if(!exst[A][C]++) ed.push_back({A,C});
		}
		else if(T==2) {
			if(!exst[B][A]++) ed.push_back({B,A}); 
			if(!exst[C][A]++) ed.push_back({C,A});
		}
		else bind(A,B,C);
	}
}
void topo(){
	queue<int> q;
	for(int i=0;i<ct;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i:red[x]) if(!--in[i]) q.push(i);
		ans.emplace_back(x);
	}
}
void outp(){
	for(int i=1;i<=V;i++) gps[go[fd(i)]].emplace_back(i);
	reverse(ans.begin(),ans.end());
	printf("%d",ans.size());
	for(int i:ans){
		printf("\n%d",gps[i].size());
		for(int j:gps[i]) printf(" %d",j);
	}
}
int main(){
	inp();
	for(int i=1;i<=V;i++) if(!head[i]) go[i]=ct++;
	memset(exst,0,sizeof exst);
	for(ii i:ed)if(!exst[fd(i.f)][fd(i.s)]++){ //RE EDGE
		red[go[fd(i.f)]].emplace_back(go[fd(i.s)]);
		in[go[fd(i.s)]]++;
	}
	topo();
	outp();
}
