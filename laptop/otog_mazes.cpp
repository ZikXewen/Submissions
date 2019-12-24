#include<iostream>
#define MX 1005
#define MD 1000000007
using namespace std;
int N,maz[MX];
long long disc[MX];
void Input(){
	cin >> N;
	for(int i=1;i<=N;i++) cin >> maz[i];
}
int main(){
	Input();
	for(int i=1;i<=N;i++) disc[i+1]=(2*disc[i]-disc[maz[i]]+2+MD)%MD;
	cout << disc[N+1];
}
