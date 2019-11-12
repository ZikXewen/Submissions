#include <bits/stdc++.h>
using namespace std;
const int MXN = 5e4 +5;
int N,M,t,a,b,p[MXN],len[MXN];
deque<int> ed[MXN];
bool cyc[MXN];
set<int> fk;
void inp(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<=N;i++) p[i]=i;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&t,&a,&b);
		if(t){
			ed[a].emplace_back(b);
			ed[b].emplace_back(a);
			if(p[a]==p[b]){
				cyc[p[a]]=1;
				if(!(len[p[a]]&1)) fk.emplace(p[a]);
			}
			else{
				len[p[b]]--; p[b]=p[a]; len[p[a]]++;
				do {for(int i=0;i<ed[b].size();i++) if(ed[b][i]!=a) {
					len[p[ed[b][i]]]--;
					len[p[b]]++;
					p[ed[b][i]]=p[b];
					a=b;
					b=ed[b][i];}
				}
				while(ed[b].size()>1);
			}
		}
		else{
			if(ed[a].back()==b)ed[a].pop_back(); else ed[a].pop_front();
			if(ed[b].back()==a)ed[b].pop_back(); else ed[b].pop_front(); 
			if(cyc[p[a]]) {cyc[p[a]]=0; fk.erase(p[a]);}
			else{
				len[p[b]]--; p[b]=b; len[b]++;
				do {for(int i=0;i<ed[b].size();i++) if(ed[b][i]!=a) {
					len[p[ed[b][i]]]--;
					len[p[b]]++;
					p[ed[b][i]]=p[b];
					a=b;
					b=ed[b][i];}
				}
				while(ed[b].size()>1);
			}
		}
		for(int i=1;i<=N;i++) cout << p[i] << ' ' ; cout << endl;
		for(int i=1;i<=N;i++) cout << len[p[i]] <<' '; cout << endl;
		//for(int k=1;k<=N;k++) {for(int j:ed[k]) cout << j << ' '; cout << endl;}
		if(fk.empty()) printf("yes\n");
		else printf("no\n");
	}
}
int main(){
	inp();
}
/*
6 15
1 2 4
1 6 4
1 5 2
1 6 5
0 4 2
1 2 3
1 4 3
*/
