#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = log2(1e18) + 1;
const long MD = 98765431;
long ar[X][2][2] = {1, 2, 1, 1}, an[2][2], id[2][2] = {1, 0, 0, 1}, N;
void mul(long a[2][2], long b[2][2], long c[2][2]){
	long te[2][2] = {};
	for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) for(int k = 0; k < 2; ++k) te[i][j] += (a[i][k] * b[k][j]) % MD;
	for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) c[i][j] = te[i][j];
}
void prt(long a[2][2]){ cout << ((a[0][0] << 1) + (a[1][0] << 1) + a[0][1] + a[1][1]) % MD << '\n'; }
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 1; i < X; ++i) mul(ar[i - 1], ar[i - 1], ar[i]);
	for(int i = 0, ct; i < N; ++i){
		long t; cin >> t; --t; ct = 0;
		an[0][0] = an[1][1] = 1, an[0][1] = an[1][0] = 0;
		do if(t & 1) mul(an, ar[ct], an); while(t >>= 1 && ++ct);
		prt(an);
	}
}
