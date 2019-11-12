#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,w,a;
long long bar[6000005]={2},v[6000005];
void Input(){
	cin >> n >> w;
	for(int i=1;i<=n;i++){
		cin >> a;
		v[i]=v[i-1]+a;
	}
}
int b_search(int st,int ed,int bk){ //cout << st << ' ' << ed << endl;
	while(st+1<ed){
		int md=(st+ed)/2;
		if(v[bk]-v[bar[md]-1]>0) st=md;
		else ed=md;
	}
	return ed;
}
void Barrier(){
	int ft=1,bk=1,an=0,_an=0;
	for(int i=1;i<=n;i++){
		bar[bk++]=i;
		if(v[i]<=v[i-1]) bk=b_search(ft,bk-1,i);
		
		long long tem=v[i]-v[bar[ft]-1];
		if(tem>an){
			an=tem;
			_an=i-bar[ft]+1;
		}
		if(tem==an&&i-bar[ft]<_an) _an=i-bar[ft]+1;
		
		if(i-bar[ft]+1>=w) ft++;
	}
	cout << an << endl << _an;
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	Barrier();
}
