#include <bits/stdc++.h>
using namespace std;
string in, cp; int an[1005];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> in; cout << 'x'; cp = (in += '0');
	for(int i = 0, st = 0; i < in.length() - 1; ++i){
		if(in[i] > '2') st = i;
		else if(in[i] > '0' && in[i + 1] == '0' || in[i] == '2'){
			for(int j = st; j <= i; ++j) if(cp[j] > '0' && cp[j + 1] > '0') an[j] = 1, --cp[j + 1]; else an[j] = 0;
			in[i] = cp[i], in[i + 1] = cp[i + 1];
		}
		else if(in[i] > '0') an[i] = 1, --in[i + 1];
	} 
	for(int i = 0; i < in.length() - 2; ++i) cout << (an[i]? '-' : '.') << 'x';
}
