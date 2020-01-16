#include<cstdio>
#include<algorithm>
#define MXN 1000002
using namespace std;
int A,B,C,D,v[MXN],ar[MXN],mx,an,an2;
int main(){
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for(int i=1;i<MXN;i++) ar[i]=i; 
	for(int i=2;i<MXN;i++) if(ar[i]>1) for(int j=i,tem=ar[i];j<MXN;j+=i) {v[j]++; ar[j]/=tem;}
	for(int i=1;i<MXN;i++){
		int x=(B/i)*i,y=(D/i)*i;
		if(x>=A&&y>=C)	if(mx<v[i]||(mx==v[i]&&(an+an2<x+y||(an+an2==x+y&&an<x)))){mx=v[i]; an=x; an2=y;}
	}
	printf("%d %d",an,an2);
}
