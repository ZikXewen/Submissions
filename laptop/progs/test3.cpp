#include <bits/stdc++.h>
using namespace std;
 
const int N = 1505;
const int K = 55;
 
int n, m;
int arr[N];
int dp[K][N], cost[N][N];
 
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
    fill_n(dp[0], K*N, (int)1.5e9);
    for(int i = 1; i <= n; ++i) {
        priority_queue<int> Ql;
        priority_queue<int, vector<int>, greater<int>> Qr;
        int suml = 0, sumr = 0;
        for(int j = i; j <= n; ++j) {
            Qr.emplace(arr[j]), sumr += arr[j];
            if(Ql.size() >= 1 && Ql.top() > Qr.top()) {
                int a = Ql.top(), b = Qr.top();
                Ql.pop(), Qr.pop();
                suml += a, sumr -= b;
                Ql.emplace(b), suml -= b;
                Qr.emplace(a), sumr += a;
            }
            if(Ql.size() + 1 < Qr.size()) {
                int a = Qr.top(); Qr.pop();
                sumr -= a, suml -= a;
                Ql.emplace(a);
            }
            cost[i][j] = suml + sumr + Qr.top() * ((int)Ql.size() - (int)Qr.size());
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k-1] + cost[k][j]);
            }
        }
    }
    printf("%d\n", dp[m][n]);
}
