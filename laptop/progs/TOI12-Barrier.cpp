#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,n,w,arrsz=0,arr[100005],ret=0,ans=0;
vector<int> v;
pair<int,int> Barrier(){
	for(int i=0;i<n;i++){
		if(v[i]<=0) arrsz=lower_bound(arr,arr+arrsz,-v[i])-arr;
		if(arrsz>=w)
			for(int j=0;j<w;j++) arr[j]=arr[j+1]+v[i];
		else{
			arrsz++;
			for(int j=0;j<arrsz;j++) arr[j]+=v[i];
		}
		if(arr[0]>ret) {ret=arr[0]; ans=arrsz;}
		if(arr[0]==ret) ans=min(ans,arrsz);
		cout << arr[0] << endl;
	}
	return {ret,ans};
}
int main(){
	cin >> n >> w >> a;
	v.push_back(a);
	for(int i=1;i<n;i++){
		cin >> a;
		v.push_back(v.back()+a);
	}
	auto x=Barrier();
	cout << x.first << endl << x.second;
}
