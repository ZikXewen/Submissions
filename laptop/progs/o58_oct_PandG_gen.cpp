#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("in","w",stdout);
	int K = 10;
	pair<int, int> go[105];
	bool vs[105][105];
	srand(time(NULL)); cout << K << "\n";
	while(K--){
		memset(vs, 0, sizeof vs);
		int R = rand() % 99 + 1, C = rand() % 99 + 1, N = rand() % 99 + 1, T = rand() % 999 + 1;
		for(int i = 0; i <= N; i++) go[i] = {rand() % R, rand() % C}, vs[go[i].first][go[i].second] = 1;
		cout << R << ' ' << C << ' ' << N << ' ' << T << ' ';
		cout << go[0].first << ' ' << go[0].second << '\n';
		for(int i = 1; i <= N; i++) cout << rand() % (T + 1) << ' ' << go[i].first << ' ' << go[i].second << '\n';
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++) {
				if(vs[i][j]) cout << '.';
				else cout << ((rand() & 1)? '.' : '#');
			}
			cout << '\n';
		} 
	}
}
