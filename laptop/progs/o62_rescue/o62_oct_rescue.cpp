#include <bits/stdc++.h>
#include "rescuelib.cpp"
using namespace std;
int main(){
	int r, c; get_size(r, c);
	int tl = drop_robot(1, 1), tr = drop_robot(1, c), bl = drop_robot(r, 1), br = drop_robot(r, c);
	if(tl != -1 && tr != -1) {
		int te = (tl + tr + 1 - c) >> 1;
		answer(te + 1, tl - te + 1);
	}
	if(bl != -1 && br != -1){
		int te = (bl + br + 1 - c) >> 1;
		answer(r - te, bl - te + 1);
	}
	if(tl != -1 && bl != -1){
		int te = (tl + bl + 1 - r) >> 1;
		answer(tl - te + 1, te + 1);
	}
	if(tr != -1 && br != -1){
		int te = (tr + br + 1 - r) >> 1;
		answer(tr - te + 1, c - te);
	}
	if(tl != -1){
		int ll = 1, rr = r;
		while(ll < rr){
			int m = (ll + rr + 1) >> 1;
			int te = drop_robot(m, 1);
			if(te == -1 || drop_robot(m - 1, 1) < te) rr = m - 1;
			else ll = m;
		}
		answer(ll, tl - ll + 2);
	}
	if(tr != -1){
		int ll = 1, rr = r;
		while(ll < rr){
			int m = (ll + rr + 1) >> 1;
			int te = drop_robot(m, c);
			if(te == -1 || drop_robot(m - 1, c) < te) rr = m - 1;
			else ll = m;
		}
		answer(ll, c - (tr - ll + 1));
	}
	if(bl != -1){
		int ll = 1, rr = r, te;
		while(ll < rr){
			int m = (ll + rr) >> 1;
			te = drop_robot(m, 1);
			if(te == -1 || drop_robot(m + 1, 1) < te) ll = m + 1;
			else rr = m;
		}
		answer(ll, bl + ll - r + 1);
	}
	if(br != -1){
		int ll = 1, rr = r, te;
		while(ll < rr){
			int m = (ll + rr) >> 1;
			te = drop_robot(m, c);
			if(te == -1 || drop_robot(m + 1, c) < te) ll = m + 1;
			else rr = m;
		}
		answer(ll, c - (br + ll - r));
	}
}
/*
100 100
69 69
2
3 1
3 70
4 70
100 70

100 100
69 69
2
70 1
70 70
1 70
69 70

5 4
4 2
2
3 1 3 3
4 3 5 3

5 4
3 3
2
1 2 4 2
4 3 4 4

5 4
3 3
2
2 2 5 2
2 3 2 4
*/
