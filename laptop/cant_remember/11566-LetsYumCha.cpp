#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int n,x,t,k;
vector<int> yourfav,price;
vector<double> avgfav;
double dp(int cur,double lef){
	if(lef<0) return -10001;
	if(cur==k) return 0;
	return max(dp(cur+1,lef),max(dp(cur+1,lef-price[cur])+avgfav[cur],dp(cur+1,lef-2*price[cur])+2*avgfav[cur]));
}
int main(){
	while(cin >> n >> x >> t >> k&&n){ // Friends, Each, Tea, Dimsum
		yourfav.clear();avgfav.clear();price.clear();
		x=(n+1)*(x-t);
		for(int i=0;i<k;i++){
			int prc;
			cin >> prc >> t;
			price.push_back(prc);
			yourfav.push_back(t);
			int val=t;
			for(int j=0;j<n;j++){
				cin >> t; val+=t;
			}
			avgfav.push_back(double(val)/(n+1));
		}
		cout << setprecision(2) << fixed << dp(0,double(x)*10/11) << endl;
	}
}
