#include <bits/stdc++.h>
#include "alienslib.h"
#include "alienslib.cpp"
using namespace std;
int N, M, x, y;
int mv, l, r;
int main() {
	get_size_and_start(N, x, y);
//	scanf("%d %d %d", &N, &x, &y);
	for(mv = 1, r = x; r + mv <= N && examine(r + mv, y); mv <<= 1) r += mv;
	for(mv >>= 1; mv; mv >>= 1) if(examine(r + mv, y)) r += mv;
		
	for(mv = 1, l = x; l - mv > 0 && examine(l - mv, y); mv <<= 1) l -= mv;
	for(mv >>= 1; mv; mv >>= 1) if(examine(l - mv, y)) l -= mv;
		
	M = r - l + 1, x = r - (M >> 1);
	for(int i = (1 << int(log2(M))); i; i >>= 1) if(examine(x, y + i)) y += i;
	y -= (M >> 1);
	
	if(x - M > 0 && y - M > 0 && x + M <= N && y + M <= N && examine(x - M, y - M) && examine(x - M, y + M) && examine(x + M, y - M) && examine(x + M, y + M) && !(examine(x + (M << 1), y + (M << 1)) && examine(x - (M << 1), y - (M << 1))))
		x -= M, y -= M;
	
	if(y + (M << 2) <= N && examine(x, y + (M << 2))) y += (M << 1);
	else if(y - (M << 2) > 0 && examine(x, y - (M << 2))) y -= (M << 1);

	if(x + (M << 2) <= N && examine(x + (M << 2), y)) x += (M << 1);
	else if(x - (M << 2) > 0 && examine(x - (M << 2), y)) x -= (M << 1);

	solution(x, y);
}
/*
2000000000
31
100 100
131 131
*/
