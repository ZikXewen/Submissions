#include<cstdio>
using namespace std;
int H,N,L,mx,b[5005],a;
int main(){
	scanf("%d%d%d",&H,&L,&N); H+=L;
	while(N--) {scanf("%d",&a); b[a]++;}
	for(int i=L;i<=H;i++) if(b[i]>mx) mx=b[i];
	printf("%d",mx);
}
