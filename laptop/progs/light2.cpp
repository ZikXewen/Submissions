#include<iostream>
using namespace std;
long m,n,chk=0;
void sw(long long &a, long long &b){
	long long t=a;
	a=b;
	b=t;
}
void ins(long long weight, long long value, long long items[][2],long cur){
	items[cur][0]=weight; items[cur][1]=value;
	while(cur!=0&&items[cur][0]>items[cur-1][0]){
		sw(items[cur][1],items[cur-1][1]);
		sw(items[cur][0],items[cur-1][0]);
		cur--;
	}
}
void out(long long items[][2],long a){
	if(a<0){
		cout << 0;
		chk++;
	}
	else{
		cout << items[a][1];
		items[a][1]=-1;
	}
}
int main(){
	long i=0,j=0;
	long long cwei,cval;
	char in;
	cin >> n >> m;
	long long items[100000][2]={};
	while(i<n||j<m){
		cin >> in;
		switch(in){
			case 'A':
				cin >> cwei >> cval;
				ins(cwei,cval,items,i++);
				break;
			case 'B':
				out(items,i-j-1+chk);
				j++; 
				break;
		}
	}
}
