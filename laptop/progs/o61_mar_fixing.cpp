#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
int N, M, K, u[2], an;
vector<int> ar;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K;
	for(int i = 0; i < M; ++i){ cin >> u[i & 1]; if(i) ar.emplace_back(abs(u[0] - u[1]) - 1); }
	sort(all(ar));
	for(int i = 0; i <= (int)ar.size() - K; ++i) an += ar[i];
	cout << an;
}
