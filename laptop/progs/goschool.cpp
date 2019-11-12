#include<iostream>
#include<cstring>
using namespace std;
bool v[50][50]{}; long long vst[50][50];
bool val(int cx,int cy){
	if(cx<0||cy<0) return false;
	if(v[cx][cy]) return false;
	return true;
}
long long dp(int cox,int coy){
	if(vst[cox][coy]!=-1) return vst[cox][coy];
	if(cox==0&&coy==0) return vst[cox][coy]=1; // Start
	if(!val(cox,coy-1)){ 
		if(!val(cox-1,coy)) return vst[cox][coy]=0; // Can't go back
		return vst[cox][coy]=dp(cox-1,coy); // Horizontal only
	}
	if(!val(cox-1,coy)) return vst[cox][coy]=dp(cox,coy-1); // Vertical only
	return vst[cox][coy]=dp(cox,coy-1)+dp(cox-1,coy); // Both
}
int main(){ 
	memset(vst,-1,sizeof vst);
	int m,n,o; cin >> m >> n >> o;
	for(int i=0;i<o;i++){
		int cx,cy; cin >> cx >> cy;
		v[cx-1][cy-1]=true;
	}
	cout << dp(m-1,n-1);
}
