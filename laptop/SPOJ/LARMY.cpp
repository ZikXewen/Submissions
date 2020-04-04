#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int N, K; cin >> N >> K;
	vi in(N), mp(N);
	for(int i = 0; i < N; ++i) cin >> in[i], mp[i] = in[i];
	sort(all(mp)); mp.resize(unique(all(mp)) - mp.begin());
	vector<vi> sm(N, vi(mp.size() + 1)), dp(N, vi(N)), an(N, vi(K + 1, 1e9)), ct(N, vi(K));
	for(auto &i: in) i = lower_bound(all(mp), i) - mp.begin();
	for(int i = 0; i < N; ++i) ++sm[i][in[i]];
	for(int i = 0; i < N; ++i) for(int j = mp.size() - 1; j >= 0; --j) 
		sm[i][j] += sm[i][j + 1] + (i? sm[i - 1][j] : 0) - (i? sm[i - 1][j + 1] : 0);
	for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j) 
		dp[i][j] = dp[i][j - 1] + sm[j - 1][in[j] + 1] - (i? sm[i - 1][in[j] + 1] : 0);
	for(int i = 0; i < N; ++i) an[i][0] = dp[0][i];
	for(int i = 1; i < N; ++i) for(int j = min(i, K - 1), ck = 0; j; --j, ck = 1) 
		for(int k = max(ct[i - 1][j], j - 1); k <= (ck? ct[i][j + 1] : i - 1); ++k)
			if(an[i][j] >= an[k][j - 1] + dp[k + 1][i])
				an[i][j] = an[k][j - 1] + dp[k + 1][i], ct[i][j] = k;
	cout << an[N - 1][K - 1];
}