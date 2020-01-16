#include <bits/stdc++.h>
#include "crectlib.h"
#include "crectlib.cpp"
using namespace std;
int N = gridsize(), l = 1, r = N, t = 1, b = N;
int rh, cv, cch, rcv, cchl, cchr, rcvt, rcvb;
bool ck(int r1, int c1, int r2, int c2){
	if(c1 > N || r1 > N || c2 > N || r2 > N || c1 < 1 || r1 < 1 || c2 < 1 || r2 < 1) return 0;
	return rect(r1, r2, c1, c2);
}
int main(){
	while(l < r) {
		int m = (l + r) >> 1;
		if(ck(1, l, N, m)) r = m;
		else l = m + 1;
	}
	while(t < b) {
		int m = (t + b) >> 1;
		if(ck(t, l, m, l)) b = m;
		else t = m + 1;
	}
	if(ck(t + 1, l, t + 1, l) || ck(t - 1, l, t - 1, l)) cv = l, rcv = rcvt = rcvb = t; // Collumn Vertical, Row Check Vertical
	if(ck(t, l + 1, t, l + 1) || ck(t, l - 1, t, l - 1)) rh = t, cch = cchl = cchr = l; // Row Horizontal, Collumn Check Horizontal
	if(!cv) {
		if(ck(1, 1, rh - 1, N)) t = 1, b = rh - 1;
		else t = rh + 1, b = N;
		l = 1, r = N;
		while(l < r) {
			int m = (l + r) >> 1;
			if(ck(t, l, b, m)) r = m;
			else l = m + 1;
		}
		while(t < b) {
			int m = (t + b) >> 1;
			if(ck(t, l, m, l)) b = m;
			else t = m + 1;
		} cv = l, rcv = rcvt = rcvb = t;
	} if(!rh) {
		if(ck(1, 1, N, cv - 1)) l = 1, r = cv - 1;
		else l = cv + 1, r = N;
		t = 1, b = N;
		while(t < b) {
			int m = (t + b) >> 1;
			if(ck(t, l, m, r)) b = m;
			else t = m + 1;
		}
		while(l < r) {
			int m = (l + r) >> 1;
			if(ck(t, l, t, m)) r = m;
			else l = m + 1;
		}
		rh = t, cch = cchl = cchr = l;
	}
	for(int i = (1 << int(log2(N))); i; i >>= 1) if(ck(rh, cchr + i, rh, cchr + i) && ck(rh, cchr + i - 1, rh, cchr + i - 1)) cchr += i; // Go Right
	for(int i = (1 << int(log2(N))); i; i >>= 1) if(ck(rcvb + i, cv, rcvb + i, cv) && ck(rcvb + i - 1, cv, rcvb + i - 1, cv)) rcvb += i; // Go Bottom
	for(int i = (1 << int(log2(N))); i; i >>= 1) if(ck(rh, cchl - i, rh, cchl - i) && ck(rh, cchl - i + 1, rh, cchl - i + 1)) cchl -= i; // Go Left
	for(int i = (1 << int(log2(N))); i; i >>= 1) if(ck(rcvt - i, cv, rcvt - i, cv) && ck(rcvt - i + 1, cv, rcvt - i + 1, cv)) rcvt -= i; // Go Top
	report(rh, cchl, rh, cchr, rcvt, cv, rcvb, cv);
}
// col vert, row hor
