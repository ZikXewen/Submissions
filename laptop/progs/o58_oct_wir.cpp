#include <bits/stdc++.h>
#define tp k.top()
using namespace std;
stack<int> k;
const int X = 1e5 + 5;
int mic[X], ar[X];
int main(){
	int n, m, q;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
		while(!k.empty() && ar[tp] > ar[i]) k.pop();
		if(!k.empty()) mic[i] = max(mic[tp], ar[i] - ar[tp]);
		k.push(i);
	}
	sort(mic, mic + n);
	while(m--){
		scanf("%d", &q);
		printf("%d\n",n - (upper_bound(mic, mic + n, q) - mic));
	}
}
