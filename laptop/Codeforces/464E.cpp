#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+5;
class tr{ public:
	int w; tr *l,*r;
	tr(){w=0, l=r=this;}
} *ver[MXN];
class ii{ public: int f,g;};
vector<ii> ed[MXN];
int N,M,S,T;
bool vst[MXN];
priority_queue<ii,vector<ii>,comp> q;
void dijk(){
	q.push(S);
	while(!q.empty()){
		ii x=q.top(); q.pop();
		vst[x.f]=1;
		for(ii i:ed[x.f]) if(!vst[x.f]){
			ud()
			vst[i.f]=1; q.push({i.f,x.g});
		}
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1,a,b,c;i<=M;i++){
		scanf("%d%d%d",&a,&b,&c);
		ed[a].push_back({b,c});
		ed[b].push_back({a,c});
	}
	scanf("%d%d",&S,&T);
	dijk();
}
