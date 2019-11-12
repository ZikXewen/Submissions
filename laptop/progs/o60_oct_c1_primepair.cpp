#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 5;
int sv[X], ct[X];
int main(){
	int u, v, w, z, a1, a2, mx = 0;
	scanf("%d %d %d %d", &u, &v, &w, &z);
	for(int i = 2; i <= z; i++){
		if(sv[i]) continue; sv[i] = ct[i] = 1;
		for(int j = i << 1; j <= z; j += i) sv[j] = i;
	}
	for(int i = 2; i <= z; i++) if(sv[i] > 1) ct[i] = ct[i/sv[i]] + 1;
	for(int i = 2; i <= z; i++){
		int b = v - (v % i), d = z - (z % i);
		if(u > b || w > d) continue;
		if(ct[i] > mx) mx = ct[i], a1 = b, a2 = d;
		else if(ct[i] == mx){
			if(b + d > a1 + a2) a1 = b, a2 = d;
			else if(b + d == a1 + a2 && b > a1) a1 = b, a2 = d;
		}
	}
	printf("%d %d", a1, a2);
}
