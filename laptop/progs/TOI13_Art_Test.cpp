#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#define TREESZ 4000000
#define MX 1000000
#define ii pair<int,int>
using namespace std;
class iii{
	public:
		int po,he,in;
};
bool comp(const iii &L,const iii &R){
	return L.po<R.po;
}
int tree[TREESZ],ind=1,n,m,a,b,c,d,emp=0,ct=1,hsh[MX],cpy[MX];
long long ans=0;
vector<iii> v;
set<int> mp={1};

// Get Value : cpy(x)  //  Get Index : hsh(x)  //

void Input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c >> d;
		v.push_back({a,++b,d});
		v.push_back({a+c,b,-d});
		mp.insert(b);
	}
	for(int i:mp){
		cpy[ct]=i;
		hsh[i]=ct++;
	}
}
void Put(int lw,int hg,int pos,int ps,int nm){
	if(ps<lw||ps>hg) return;
	tree[pos]+=nm;
	if(lw==hg) return;
	int md=(lw+hg)>>1;
	Put(lw,md,(pos<<1)|1,ps,nm);
	Put(md+1,hg,(pos+1)<<1,ps,nm);
}
int Get(int lw,int hg,int pos,int ps){
	if(lw>ps) return 0;
	if(hg<=ps) return tree[pos];
	int md=(lw+hg)>>1;
	return Get(lw,md,(pos<<1)|1,ps)+Get(md+1,hg,(pos+1)<<1,ps);
}
int bins(int st,int ed){ 
	int md=(st+ed)>>1;
	if(st>ed) return md+1;
	int anmd=Get(0,ct,0,md);
	if(anmd<=m)	return bins(st,md-1);
	return bins(md+1,ed);
}
int binsx(int st,int ed){
	int md=(st+ed)>>1;
	if(st>ed) return md;
	int anmd=Get(0,ct,0,md);
	if(anmd>=m) return binsx(md+1,ed);
	return binsx(st,md-1);
}
void Art(){
	for(int i=0;i<(n<<1)-1;i++){ // 2*N
		Put(0,ct,0,1,v[i].in); // LOG H
		Put(0,ct,0,hsh[v[i].he],-v[i].in); // LOG H
		//if(v[i].in>0) emp++; else emp--;
		if(/*!emp||*/v[i+1].po==v[i].po) continue;
		ans+=(cpy[binsx(1,ct)+1]-cpy[bins(1,ct)])*(v[i+1].po-v[i].po); // 2 LOG^2 H
	}
	cout << ans;
}
int main(){
	//freopen("inp.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	Input(); 
	sort(v.begin(),v.end(),comp); // LOG 2N
	Art(); // 2N(LOG H+LOG^2 H)
	//fclose(stdin);
}
