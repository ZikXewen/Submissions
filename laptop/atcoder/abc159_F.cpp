#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 3005;
const long MD = 998244353;
int N, K, in[X];
long mm[X][X][2];
bool base;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) cin >> in[i];
	for(int i = 0; i < N; ++i) for(int j = 0; j <= K; ++j, ++in[i]){
		base = !j; 
		(mm[i + 1][j][0] += base + mm[i][j][0]) %= MD;
		(mm[i + 1][j][1] += base + mm[i][j][0] + mm[i][j][1]) %= MD;
		if(in[i] <= K){ 
			(mm[i + 1][in[i]][0] += base + mm[i][j][0]) %= MD;
			(mm[i + 1][in[i]][1] += base + mm[i][j][0]) %= MD;
		}
	}
	cout << mm[N][K][1];
}