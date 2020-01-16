#include <bits/stdc++.h>
using namespace std;
const int X = 400;
int M, ct;
vector<string> ar;
vector<int> sh;
bool stat[X];
void rev(int u, int v){
	int uu = gt(u), vv= gt(v);
	ckfl(u), chfl(v);
	
}
int main(){
	string in; cin >> in >> N; add(in, 0);
	while(N--){
		cin >> N;
		if(N[0] == 'R') cin >> u >> v, rev(u, v);
		else cin >> u >> in, add(in, u);
	}
}
