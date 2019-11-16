#include <bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5;
int N, M, vs[X], ar[X];
bool no[X];
int main(){
	scanf("%d%d", &N, &M);
	for(int i = 1, u; i <= N; ++i){
		scanf("%d", &ar[i]);
		if(vs[ar[i]]) for(int j = vs[ar[i]]; j < i; ++j) no[ar[j]] = 1;
		vs[ar[i]] = i;
	}
	
}