#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1001][1001],n,m,a,k,mx=0;
int main(){
    scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        scanf("%d",&a); arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+a;
    }
    for(int i=k;i<=n;i++) for(int j=k;j<=m;j++){
        int sm=arr[i][j]-arr[i-k][j]-arr[i][j-k]+arr[i-k][j-k];
        mx=max(sm,mx);
    }
    printf("%d",mx);
}
