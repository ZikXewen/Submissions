#include<iostream>
using namespace std;
int mx,n,arr[20000],st,cm=0;
pair<int,int> ck[20000];
pair<int,int> dp(int p){
	if(ck[p].first!=-1&&ck[p].second!=-1) return ck[p];
	if(p==1) return make_pair(arr[1],1);
	if(dp(p-1).first >= 0){
		return ck[p] = make_pair(dp(p-1).first+arr[p],dp(p-1).second);
	}
	else{
		return ck[p] = make_pair(arr[p],p);
	}
}
int main(){
	int ca; cin >> ca;
	for(int x=1;x<=ca;x++){
		mx=0;
		cin >> n;
		for(int i=1;i<n;i++){
			ck[i]=make_pair(-1,-1);
			cin >> arr[i];
		}
		for(int i=1;i<n;i++){
			if(dp(i).first>mx||(dp(i).first==mx&&i-dp(i).second>cm)){
				mx=dp(i).first;
				st=dp(i).second;
				cm=	i-dp(i).second;
			}
		}
		if(mx>0) cout << "The nicest part of route " << x << " is between stops " << st << " and " << st+cm+1 << endl;
		else cout << "Route " << x << " has no nice parts" << endl;
	}
}
