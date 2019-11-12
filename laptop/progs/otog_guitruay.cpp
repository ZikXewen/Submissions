#include<iostream>
#define MAX 1000002
#define ii pair<int,int>
using namespace std;
ii chord[MAX];
int x,y,z,a,b,ct=0,an,mx=0,play[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> x >> y >> z;
	for(int i=1;i<=y;i++){
		cin >> a >> b;
		chord[i]=ii(a,b);
	}
	while(z--){
		cin >> a;
		play[chord[a].first]++;
		play[chord[a].second+1]--;
	}
	for(int i=1;i<=MAX;i++){
		ct+=play[i];
		if(ct>mx){
			mx=ct; an=i;
		}
	}
	cout << an << " " << mx;
}
