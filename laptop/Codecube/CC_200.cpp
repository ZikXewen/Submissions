#include <bits/stdc++.h>
using namespace std;
string u, v;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> u >> v;
	cout << (u == v ? -1 : (int)max(u.length(), v.length()));
}
