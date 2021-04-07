#include <bits/stdc++.h>
using namespace std;
int c, d, step = 29;
bool de;
int prt(int u, int v){
    int ret;
    printf("? %d %d\n", u, v); cin >> ret;
    return ret;
}
void t2(){
    if(step < 0) return;
    int u = prt(c, d + (1 << step));
    if(u == 1) c += (1 << step), d += (1 << step);
    --step; t2();
}
void t1(){
    int u = prt(c, d + (1 << step)), v = prt(c + (1 << step), d);
    if(!u){
        if(de) c += (1 << step);
        else d += (1 << step);
        --step; t2(); return;
    }
    if(de){
        if(u == 1){
            if(v == 1) c += (1 << step);
            else c += (1 << step), d += (1 << step);
        } else {
            if(v == 1);
            else c += (1 << step), de = 0;
        }
    } else {
        if(u == 1){
            if(v == 1) d += (1 << step), de = 1;
            else c += (1 << step), d += (1 << step);
        } else {
            if(v == 1);
            else d += (1 << step);
        }
    }
    --step; t1();
}
int main(){
    int tm = prt(0, 0);
    de = (tm == 1);
    if(tm) t1();
    else t2();
    printf("! %d %d\n", c, d);
}
/*
	    0 0     0 1	    1 0
10 11	 <       >	     <
00 11	 <       <	     <
00 01    <   	 <	     >
01 10	 <       >	     >

11 10    >       >       <
11 00    >       >       >
01 00    >       <       >
10 01    >       <       <

00 10    <       =       =
01 11    <       =       =

11 01    >       =       =
10 00    >       =       =

00 00    =       <       >
01 01    =       <       >
10 10    =       >       <
11 11    =       >       <
*/