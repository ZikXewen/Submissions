#include<iostream>
using namespace std;
int n;
int chk(int ck,int *arr){
	int strn=ck;
	if(arr[0]>strn) return 0;
	if(arr[0]==strn) strn--;
	for(int i=1;i<n;i++){
		int dif=arr[i]-arr[i-1];
		if(dif==strn) strn--;
		else if(dif>strn) return 0;
	}
	return 1;
}
int srch(int st, int ed,int *arr){
	if(st>ed) return 0;
	int mid=(st+ed)/2;
	if(chk(mid,arr)){
		if(chk(mid-1,arr)) return srch(st,mid-1,arr);
		else{
			cout << mid << endl;
			return 1;
		}
	}
	else return srch(mid+1,ed,arr);
}

int main(){
	int t;
	cin >> t;
	for(int z=1;z<=t;z++){
		cin >> n;
		int arr[n],max=0,maxp=0;
		for(int i=0;i<n;i++)
			cin >> arr[i];
		cout << "Case " << z << ": ";
		srch(0,arr[n-1],arr);
	}
}
