#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int N, u, v, w; cin >> N; while(N--)
	cin >> u >> v >> w,
	cout << (((u == 1 && !w) or (v == 1 && !u) or (w == 1 & !v) or (u && v && w))? "YES\n" : "NO\n");
}
