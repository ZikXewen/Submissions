#include <bits/stdc++.h>
using namespace std;
const int X = 3e5;
int t, ft[X + 5];
long long sm;
char s[X + 5], ss[X + 5];
deque<int> v[128];
void ud(int x) { for(; x <= X; x += -x & x) ft[x]--; }
int qu(int x){ int ret = 0; for(; x; x -= -x & x) ret += ft[x]; return ret;}
int main(){
	scanf("%d %s %s", &t, s + 1, ss + 1);
	int le = strlen(s + 1), lee = strlen(ss + 1);
	for(int i = 1; i <= le; i++) ft[i] = i & -i, v[s[i]].emplace_back(i);
	for(int i = 1; i <= lee; i++) {
		if(v[ss[i]].empty()) return !printf("-1"); 
		sm += qu(v[ss[i]].front());
		if(t) ud(v[ss[i]].front());
		v[ss[i]].pop_front();
	}
	printf("%lld", sm);
}
