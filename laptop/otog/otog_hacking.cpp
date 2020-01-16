#include<iostream>
#include<cmath>
#include"hacking.h"
using namespace std;
/*const int _n=9; int a[_n]={0,0,0,1,1,1,1,1,1};
int GetN(){
	return _n;
}
bool CheckF(int _x){
	return a[_x];
}
*/
int main(){
	int _n=GetN(),Q=sqrt(_n),i=1;
	while(i+Q<_n&&!CheckF(i+Q)) i+=Q;
	while(++i<_n&&!CheckF(i));
	cout << --i;
}
