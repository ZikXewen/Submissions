#include<iostream>
using namespace std;
int main(){
	//freopen("file.txt","w",stdout);
	int n,m;
	while(cin >> n >> m){
		int max=0;
		int k[n];
		for(int i=0;i<n;i++){
			cin >> k[i];
			if(k[i]>max) max=k[i];
		}
		max--;
		while(max++){
			int cnt=1,ck=0;
			for(int i=0;i<n;i++){
				ck+=k[i];
				if(ck>max){
					ck=k[i];
					if(++cnt>m) break;
				} 
			}
			if(cnt<=m){
				cout << max << endl;
				break;
			}
		}
	}
	//fclose(stdout);
	return 0;
}
