#include<iostream>
#include<cstring>
using namespace std;
int mem[1<<12],n; char c;
int dp(int btmk){
	int mx=0;
	if(mem[btmk]!=-1) return mem[btmk];
	for(int i=1;i<11;i++){
		if(btmk & 1<<i){
			btmk-=(1<<i);
			if(btmk&1<<(i+1)&&!(btmk&1<<(i-1)))
				mx=max(mx,1+dp(btmk-(1<<(i+1))+(1<<(i-1))));
			else if(btmk&1<<(i-1)&&!(btmk&1<<(i+1))){
				mx=max(mx,1+dp(btmk-(1<<(i-1))+(1<<(i+1))));
			}
			btmk+=(1<<i);
		}
	}
	return mem[btmk]=mx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(mem,-1,sizeof mem);
	while(n--){
		int st=0,ct=0;
		for(int i=0;i<12;i++){
			cin >> c;
			st<<=1;
			if(c=='o'){
				st|=1; ct++;
			}
		}
		cout << ct-dp(st) << endl;
	}
}
