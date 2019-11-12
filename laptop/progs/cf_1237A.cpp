#include <bits/stdc++.h>
using namespace std;
int N, o, cr;
int main(){
	scanf("%d", &N);
	while(N--) scanf("%d", &o), printf("%d\n", (o & 1)? (o >> 1) + (cr ^= 1) : (o >> 1));
}
