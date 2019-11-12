#include<iostream>
#include<set>
#include<vector>
#include<queue>
#define ii pair<int,int>
#define MXN 100005
using namespace std;
set<vector<int> > s;
bool vst[MXN];
int N,M,a,b,dg[MXN];
vector<int> v[MXN];
void flood(int st){
	vector<int> ret;
	queue<vector<int> > q;
	bool cyc=vst[st]=true;
	q.push({st,0,0}); // Current,Length,Parent
	while(!q.empty()){
		vector<int> x=q.front(); q.pop();
		bool fnd=false;
		for(int i:v[x[0]]){
			if(i==x[2]) continue; //If parent
			if(vst[i]){
				cyc=true;
				ret.emplace_back(x[1]); // Cycle
			}
			vst[i]=true; q.push({i,x[1]+1,x[0]}); fnd=true;
		}
		if(!fnd) ret.emplace_back(x[0]); //End of line
	}
	if(cyc){
		if()
	}
}
int main(){
	scanf("%d%d",&N,&M);
	while(M--){
		scanf("%d%d",&a,&b);
		dg[a]++;dg[b]++;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for(int i=1;i<=N;i++) if(dg[i]==3) flood(i);
	for(int i=1;i<=N;i++) if(!vst[i]) flood(i);
	cout << s.size();
}
