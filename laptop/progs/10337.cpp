#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int ck[100][10];
vector<int> v[10];
int dp(int pos,int alt){
//	cout << pos << " " << alt << " " << v[alt][pos] << endl;
	if(ck[pos][alt]) return ck[pos][alt];
	if(pos==0) return ck[pos][alt] = -v[0][0];
	if(pos==alt) return ck[pos][alt] = dp(pos-1,alt-1)+60 - v[alt][pos];
	if(pos==alt+1){
		if(alt==0) return ck[pos][alt] = dp(pos-1,alt)+30 - v[alt][pos];
		return ck[pos][alt] = min(dp(pos-1,alt-1)+60,dp(pos-1,alt)+30) - v[alt][pos];
	}
	if(alt==9) return ck[pos][alt] = min(dp(pos-1,alt-1)+60,dp(pos-1,alt)+30) - v[alt][pos];
	if(alt==0) return ck[pos][alt] = min(dp(pos-1,alt)+30,dp(pos-1,alt+1)+20) - v[alt][pos];
	return ck[pos][alt] = min(dp(pos-1,alt-1)+60,min(dp(pos-1,alt)+30,dp(pos-1,alt+1)+20)) - v[alt][pos];
}
int main(){
//	freopen("file.txt","w",stdout);
	int c; cin >> c;
	for(int tme=0;tme<c;tme++){
		int x;
		memset(ck,0,sizeof(ck));
		cin >> x; x/=100;
		for(int i=9;i>=0;i--){
			v[i].clear();
			for(int j=0;j<x;j++){
				int t; cin >> t; v[i].push_back(t);
			}
		}
		cout << min(dp(x-1,0)+30,dp(x-1,1)+20) << endl << endl;
		/*for(int i=9;i>=0;i--){
			for(int j=0;j<x;j++) cout << ck[j][i] << "\t";
			cout << endl;
		}*/
	}
//	fclose(stdout);
}
