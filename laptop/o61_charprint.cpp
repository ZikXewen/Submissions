#include <bits/stdc++.h>
using namespace std;
string s,t;
const int mxn = 3e5+5 , mxk = 30;
int n,cur,as[mxk][mxn],fd[mxk],ret,fw[mxn];
void ud(int x){for(;x<=mxn;x+=-x&x) fw[x]++;}
int gt(int x){int ret=0; for(;x;x-=-x&x) ret+=fw[x]; return ret;}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s >> t;
	for(auto i:s) { // O(kn)
		for(int j=0;j<mxk;j++) as[j][cur+1]=as[j][cur];
		as[i-'a'][++cur]++;
	} cur++;
	for(auto i:t){ //O(nlogn)
		i-='a';
		int x = lower_bound(as[i],as[i]+cur,++fd[i])-as[i];
		if(x==cur) {ret=-1; break;}
		ret+=x;
		if(n) ret-=gt(x), ud(x);
	}
	cout << ret;
}
/*
1
aaaaffffaaaa
fafafafa
*/
