#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string h,n; int c;
int mem[10001][101];
int dp(int ph,int pn){
	int tem=0;
	if(pn==n.length()) return 1;
	if(ph==h.length()) return 0;
	if(mem[ph][pn]!=-1) return mem[ph][pn];
	if(h[ph]==n[pn]) tem+=dp(ph+1,pn+1);
	tem+=dp(ph+1,pn);
	return mem[ph][pn]=tem;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> c;
	while(c--){
		memset(mem,-1,sizeof mem);
		if(h[0]=='0') return 0; cin >> h >> n;
		cout << dp(0,0) << endl;
	}
}
