#include<iostream>
#include<cstring>
#define MX 2001
using namespace std;
int n,mm[MX][MX],msg[8][8];
string m;
void Input(){
	cin >> n >> m;
	memset(mm,-1,sizeof mm);
	memset(msg,-1,sizeof msg);
}
int get(int pos){
	return(1<<(m[pos]-'0'));
}
int segi(int x,int y){
	if(msg[x][y]!=-1) return msg[x][y];
	int ret=0;
	if(1&x&&4&y) ret|=1;
	if((1&x&&1&y)||(2&x&&1&y)||(4&x&&2&y)) ret|=4;
	if((1&x&&2&y)||(2&x&&2&y)||(2&x&&4&y)||(4&x&&1&y)||(4&x&&4&y)) ret|=2;
	return msg[x][y]=ret;
}
int dp(int st,int ed){
	if(mm[st][ed]!=-1) return mm[st][ed];
	if(st==ed) return mm[st][ed]=get(st);
	int ret=0;
	for(int i=st;i<ed;i++){
		ret|=segi(dp(st,i),dp(i+1,ed));
	}
	return mm[st][ed]=ret;
}
int main(){
	for(int tm=0;tm<20;tm++){
		Input();
		if(dp(0,n-1)&1) cout << "yes\n";
		else cout << "no\n";
	}
}
