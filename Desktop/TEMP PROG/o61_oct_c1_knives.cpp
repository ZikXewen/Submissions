#include<bits/stdc++.h>
using namespace std;
int n,q,l,in1,in2,pos[mxn],fd[mxn],fu[mxn];
bool st[mxn];
int main(){
	scanf("%d%d%d",&n,&q,&l);
	fu[0]=n;
	while(l--){
		scanf("%c",&in1);
		if(in1 == 's'){
			scanf(" %d%d",&in1,&in2);
			if(st[in1]) ud(in1,in2);
			else uu(in1,in2);
		}
		else if(in1 == 'q'){
			scanf(" %d",&in1);
		}
		else{
			scanf(" %d",&in1);
		}
	}
}