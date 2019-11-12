#include<cstdio>
#include<cstring>
using namespace std;
int c,an,N; char s[205];
int main(){
	scanf("%s",s);
	N=strlen(s);
	for(int i=0;i<N;i++){
		if(s[i]=='(') c++;
		else if(c==0) an++;
		else c--;
	}
	printf("%d",c+an);
}
