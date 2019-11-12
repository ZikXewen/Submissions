#include<cstdio>
using namespace std;
int T,L,v,l,r;
int main(){
	scanf("%d",&T); while(T--){
		scanf("%d%d%d%d",&L,&v,&l,&r);
		int m=L/v+l/v-r/v;
		if(!(l%v)) m--;
		printf("%d\n",m);
	}
}
