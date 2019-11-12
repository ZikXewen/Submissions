#include <bits/stdc++.h>
using namespace std;
class ii{public:
	int I,J;
	ii(int II,int JJ){I=II,J=JJ;}
	bool operator<(const ii &R)const{return I<R.I;};
};
int N,M;
vector<ii> v;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1,x;i<=N;i++){
		scanf("%d",&x);
		int nw=(v.empty()? 0:v.back().I)+x;
		v.erase(lower_bound(v.begin(),v.end(),ii(nw,0)),v.end());
		v.emplace_back(nw,i);
	}
	//for(auto i:v) cout << i.I << ' ';
	for(int i=0,x;i<M;i++){
		scanf("%d",&x);
		auto it = upper_bound(v.begin(),v.end(),ii(x,0));
		if(it==v.begin()) printf("0\n");
		else printf("%d\n",(it-1)->J);
	}
}
