#include<cstdio>
using namespace std;
int N,A,a=1,b=1,c=1;
bool bo;
int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%d",&A);
		if(A==13){
			bo=true;
			c++;
		} else if(A==10){
			b++;
			if(bo) a++;
			bo=false;
		}
		else bo=false;
	}
	printf("%d %d %d",a,b,c);
}
