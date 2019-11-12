#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n; // Carriable Weight , Numbers of Items
vector<pair<int,int> > v;
int arr[110][15000];
int dp(int i, int w) { // Item , Weight Carried
	if(arr[i][w]!=-1) return arr[i][w]; // Memory
    if(w>m && m<1800) return -1000; // Unusable Discount
    if(w>m+200) return -1000; // Overload
    if(i==n){ // End
        if(w>m && w<=2000) return -1000; // Unusable Discount
        return 0; // Passed
    }
    return arr[i][w]=max(dp(i+1,w),v[i].second+dp(i+1,w+v[i].first)); // Recurse
}
int main() {
    while(cin >> m >> n) {
    	v.clear(); memset(arr, -1, sizeof(arr));
        for(int i = 0; i < n; i++){
        	int t1,t2; cin >> t1 >> t2;
        	v.push_back(make_pair(t1,t2));
		}
        cout << dp(0,0) << endl;
    }
}
