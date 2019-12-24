#include<bits/stdc++.h>
using namespace std;
bool notprm[302],pos[1005][15][70];
int n,t,pd[15],cs=1;
vector<int> pms;
bool comp(int L,int R){
	stringstream ss1,ss2;
	ss1 << L; ss2 << R;
	return ss1.str()<ss2.str();
}
void prm(){
	memset(pos,true,sizeof pos);
	for(int i=2;i*i<300;i++) if(!notprm[i])	for(int j=2*i;j<300;j+=i) notprm[j]=true;
	for(int i=2;i<300;i++) if(!notprm[i]) pms.push_back(i);
	sort(pms.begin(),pms.end(),comp);
}
bool dp(int cur,int lft,int pm){
	if(cur==0&&lft==0) return true;
	if(lft==0||cur<=0||lft<=0||pm>=pms.size()) return false;
	if(!pos[cur][lft][pm]) return false;
	//2
	if(pms[pm]!=2&&dp(cur-2*pms[pm],lft-2,pm+1)){
		pd[lft]=pd[lft-1]=pms[pm];
		return true;
	}
	//1
	if(dp(cur-pms[pm],lft-1,pm+1)){
		pd[lft]=pms[pm];
		return true;
	}
	//0
	if(dp(cur,lft,pm+1)) return true;
	
	return pos[cur][lft][pm]=false;
}
void solve(){
	if(!dp(n,t,0)) cout << "No Solution.\n";
	else{
		cout << pd[t];
		for(int i=t-1;i>0;i--) cout << '+' << pd[i];
		cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("file.txt","w",stdout);
	prm();
	while(cin >> n >> t,n,t){
		cout << "CASE " << cs++ << ":\n"; solve();
	}
//	fclose(stdout);
}
