#include<iostream>
#include<algorithm>
using namespace std;
long long N,M,i;
int main(){
	cin >> N >> M;
	cout << max(N-2*M,0LL) << ' ';
	for(i=1;(i*(i-1))>>1<M;i++);
	if((i-1)*(i-2)>>1==M) i--;
	cout << N-i;
}
