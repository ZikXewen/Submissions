#include<iostream>
#include<array>
using namespace std;
array<int,5> mem[400]={};
array<int,5> dp(int mny){
	if(mem[mny][0]!=-1) return mem[mny];
	array<int,5> ret; //i,v,x,l,c
	if(mny>=100){
		ret = dp(mny-100); ret[4]++;
	}
	else if(mny>=90){
		ret=dp(mny-90); ret[4]++; ret[2]++;
	}
	else if(mny>=50){
		ret=dp(mny-50); ret[3]++;
	}
	else if(mny>=40){
		ret=dp(mny-40); ret[3]++;ret[2]++;
	}
	else if(mny>=10){
		ret=dp(mny-10); ret[2]++; 
	}
	else if(mny==9){
		ret = {1,0,1,0,0};
	}
	else if(mny>=5){
		ret = dp(mny-5); ret[1]++;
	}
	else if(mny==4){
		ret={1,1,0,0,0};
	}
	else ret={mny,0,0,0,0};
	return mem[mny]=ret;
}
int main(){
	int n; array<int,5> ans={},sm={};
	cin >> n;
	for(int i=0;i<=n;i++) mem[i][0]=-1;
	for(int i=1;i<=n;i++){
		ans=dp(i);
		sm={sm[0]+ans[0],sm[1]+ans[1],sm[2]+ans[2],sm[3]+ans[3],sm[4]+ans[4]};
	}
	for(int i:sm) cout << i << " ";
}
