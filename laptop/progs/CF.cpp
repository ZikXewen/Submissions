#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long s,a,b,c,N;
int main(){
	scanf("%d",&N); while(N--){
		cin >> s >> a >> b >> c;
		long long m=s/c;
		cout << m+m/a*b << '\n';
	}
}
