#include<iostream>
#define MX 1000
#define MOD 1000000007
using namespace std;
bool vst[MX][MX];
int mem[MX][MX],n,m;
void Input(){
	cin >> n >> m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> vst[i][j];
	vst[0][0]=true;
	mem[0][0]=1;
}
int dp(int x,int y){
	if(vst[x][y]) return mem[x][y];
	int ret=0;
	if(x>0) ret+=dp(x-1,y);
	if(y>0) ret+=dp(x,y-1);
	vst[x][y]=true;
	return mem[x][y]=ret%MOD;
}
int main(){
	Input();
	cout << dp(n-1,m-1);
}
