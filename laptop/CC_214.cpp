#include <bits/stdc++.h>
#define long long long
using namespace std;
const long MD = 1e9 + 7;
long f(long n, long a){
	if(n == 0) return 1;
	long pre = f(n >> 1, a);
	if(n & 1) return ((pre * pre) % MD * a) % MD;
	return (pre * pre) % MD;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	while(N--){
		long n, a; cin >> n >> a; a <<= 1;
		if(!n){ cout << 0 << '\n'; continue;}
		long an = (f((n << 1) - 1 , a) - f(n - 1, a) + MD) % MD;
		an = (an * f(MD - 2 , a - 1)) % MD;
		cout << an << '\n';
	}
}
