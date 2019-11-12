#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 10;
int N;
long long v[X], ar[X];
long long fd(int l, int r){
	if(l == r) return 0LL;
	int m = (l + r) >> 1, i = l, j = m + 1, k = 0;
	long long rt = fd(l, m) + fd(m + 1, r);
	while(i <= m && j <= r) 
		if(v[i] <= v[j]) ar[k++] = v[i++];
		else ar[k++] = v[j++], rt += m - i + 1LL;
	while(i <= m) ar[k++] = v[i++];
	while(j <= r) ar[k++] = v[j++];
	for(int z = 0; z < k; z++) v[l + z] = ar[z];
	return rt;
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%lld", &v[i]);
	printf("%lld", fd(0, N - 1));
}
