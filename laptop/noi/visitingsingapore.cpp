#include <bits/stdc++.h>
using namespace std;
const int X = 5005;
int K, N, M, A, B, V[X], S[X], T[X], an = INT_MIN;
int dp[2][X][2][2];
void mxe(int &a, int b){ a = max(a, b); }
void mxe(int &a, int b, int c){ a = max(a, max(b, c)); }
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> K >> N >> M >> A >> B;
	for(int i = 1; i <= K; ++i) cin >> V[i]; // Values
	for(int i = 1; i <= N; ++i) cin >> S[i]; // Events
	for(int i = 1; i <= M; ++i) cin >> T[i]; // Interests
	memset(dp, 128, sizeof dp); dp[0][0][0][0] = dp[1][0][0][0] = 0;
	for(int i = 0; i <= N; ++i) {
		bool ii = i & 1;
		memset(dp[ii], 128, sizeof dp[ii]); dp[ii][0][0][0] = 0;
		for(int j = 1; j <= M; ++j){
			if(S[i] == T[j]) 
				mxe(dp[ii][j][0][0], max(max(dp[ii ^ 1][j - 1][0][0], dp[ii ^ 1][j - 1][0][1]), max(dp[ii ^ 1][j - 1][1][0], dp[ii ^ 1][j - 1][1][1])) + V[S[i]]);
			mxe(dp[ii][j][0][1], dp[ii][j - 1][0][1] + B, dp[ii][j - 1][0][0] + A + B);
			mxe(dp[ii][j][1][1], dp[ii][j - 1][1][1] + B, dp[ii][j - 1][1][0] + A + B); // Skip an event
			mxe(dp[ii][j][1][0], dp[ii ^ 1][j][1][0] + B, dp[ii ^ 1][j][0][0] + A + B);
			mxe(dp[ii][j][1][1], dp[ii ^ 1][j][1][1] + B, dp[ii ^ 1][j][0][1] + A + B); // Skip a day
		}
		if(i) mxe(an, max(max(dp[ii][M][0][0], dp[ii][M][0][1]), max(dp[ii][M][1][0], dp[ii][M][1][1])));
	}
	cout << an;
}