#include<iostream>
#include<algorithm>
using namespace std;
int n,mx=1,an,a[1000001],b[1000001],x;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x; a[x]=i;
	}
	for(int i=0;i<n;i++){
		cin >> x; b[(i-a[x]+n)%n]++;
	}
	for(int i=0;i<n;i++) if(b[i]>mx){
		mx=b[i]; an=i;
	}
	cout << mx << " " << an;
}
