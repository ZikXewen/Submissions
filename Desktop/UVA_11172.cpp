#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("out","w",stdout);
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		if(u<v) printf("<\n");
		else if(u>v) printf(">\n");
		else printf("=\n");
	}
}