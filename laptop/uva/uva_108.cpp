#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	//freopen("inp.txt","r",stdin);
	//freopen("file.txt","w",stdout);
	int n,dp[101],a[100][100],sum[100][101];
	while(cin >> n){
		int ans=-1270001;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
		for(int i=0;i<n;i++){
			sum[i][0]=0;
			for(int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[i][j-1]; // Each row
		}
		for(int i=0;i<n;i++) for(int j=i;j<n;j++){
			dp[0]=0;
			for(int k=0;k<n;k++){
				dp[k+1]=max(sum[k][j+1]-sum[k][i]+dp[k],sum[k][j+1]-sum[k][i]);
                ans=max(ans,dp[k+1]);
			}
		}
		cout << ans << endl;
	}
	//fclose(stdout); fclose(stdin);
}
