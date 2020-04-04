#include <bits/stdc++.h>
using namespace std;
const int X = 5005;
int N, M, K, in[X], mp[X], sm[X][X], smm[X][X];
vector<int> dp(X), te(X);
void calc(int l, int r, int otl, int otr){
	if(l > r) return;
	int m = l + r >> 1;
	pair<int, int> ret(INT_MAX, -1);
	for(int i = otl; i <= min(otr, m); ++i) ret = min(ret, {dp[i - 1] + smm[i][m], i});
	te[m] = ret.first;
	calc(l, m - 1, otl, ret.second);
	calc(m + 1, r, ret.second, otr);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for(int i = 1; i <= N; ++i) cin >> in[i], mp[i - 1] = in[i];
	sort(mp, mp + N); M = unique(mp, mp + N) - mp;
	for(int i = 1; i <= N; ++i) ++sm[i][in[i] = lower_bound(mp, mp + M, in[i]) - mp + 1];
	for(int i = 1; i <= N; ++i) for(int j = M; j; --j) 
		sm[i][j] += sm[i][j + 1] + sm[i - 1][j] - sm[i - 1][j + 1];
	for(int i = 1; i <= N; ++i) for(int j = i + 1; j <= N; ++j)
		smm[i][j] = smm[i][j - 1] + sm[j - 1][in[j] + 1] - sm[i - 1][in[j] + 1];
	for(int i = 1; i <= N; ++i) dp[i] = smm[1][i];
	for(int i = 2; i <= K; ++i) calc(i, N, i, N), dp = te;
	cout << dp[N];
}