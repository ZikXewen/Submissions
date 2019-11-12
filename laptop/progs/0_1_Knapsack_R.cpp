#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > v;
vector<int> ans;
int n,an=0,tem1,tem2,i,mem[][];
vector<int> dp(int cur,int we){ // Value until now
	if(we<0) return;
	
}
int main(){
	cin >> n; for(i=0;i<n;i++){
		cin >> tem1 >> tem2; v.push_back(make_pair(tem1,tem2));
	}
	cin >> tem1 >> tem2; dp(0,tem1);
	sort(ans.begin(),ans.end());
	for(i=0;i<tem2&&i<ans.size();i++) cout << -ans[i] << endl;
	while(i++<tem2) cout << "0" << endl;
}
