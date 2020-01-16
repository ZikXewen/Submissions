#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int r = rand() % 999 + 1, c = rand() % 999 + 1;
	int er = rand() % 999 + 1, ec = rand() % 999 + 1;
	int m = rand() % 3;
	printf("%d %d %d %d %d\n", r, c, er, ec, m);
	int wr[4], wc[4];
	for(int i = 0; i < 3; i++) wr[i] = rand() % r + 1, wc[i] = rand() % c + 1;
	
}
