#include <bits/stdc++.h>
using namespace std;
int N, u = -1005, v, w, x;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	while(N--) cin >> x, w = v - x, v = max(v, u + x), u = max(u, w);
	cout << v;
}
