#include <bits/stdc++.h>
using namespace std;
const int X = 1005;
int N, ar[X];
long long K;
long long ck(int cr){
	long long ret = (1LL + cr) * (1LL + cr) * N;
	for(int i = 1; i < N; i++) if(ar[i] - ar[i - 1] <= (cr << 1)) {
		int te = (cr << 1) - (ar[i] - ar[i - 1]) + 2;
		ret -= ((1LL * te * te) >> 2);
	}
	return ret;
}
int main() {
	scanf("%d %lld", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(ar, ar + N);
	int l = 0, r = 1e9;
	while(l < r) {
		int m = (l + r) >> 1;
		if(ck(m) >= K) r = m;
		else l = m + 1;
	}
	printf("%d", l);
}
