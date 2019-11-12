#include<cstdio>
using namespace std;
int n,k,ar[1001][1001]; bool fst=false;
int main(){
	//freopen("inp.txt","r",stdin); freopen("file.txt","w",stdout);
	while(scanf("%d %d",&n,&k)==2){
		long sm=0;
		if(fst) printf("\n");
		else fst=true;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {scanf("%d",&ar[i][j]); ar[i][j]+=ar[i-1][j]+ar[i][j-1]-ar[i-1][j-1];}
		for(int i=k;i<=n;i++){
			for(int j=k;j<=n;j++){
				int tem=ar[i][j]-ar[i-k][j]-ar[i][j-k]+ar[i-k][j-k]; sm+=tem;
				printf("%d\n",tem);
			}
		}
		printf("%ld\n",sm);
	}
	//fclose(stdin); fclose(stdout);
}
