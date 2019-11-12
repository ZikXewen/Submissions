#include<cstdio>
using namespace std;
int main(){
		char s[3],op[5]={"ESWN"}; int n,x=0,y=0,dir=0,cox[4]={1,0,-1,0},coy[4]={0,-1,0,1}; bool dead=false; scanf("%d",&n); while(n--){
		int d; scanf("%s %d",s,&d);
		if(dead) continue;
		switch(s[0]){
			case 'L' : dir=(dir+3)%4; break;
			case 'R' : dir=(dir+1)%4; break;
			case 'B' : dir=(dir+2)%4; break;
			default  :;
		}
		x+=cox[dir]*d; y+=coy[dir]*d;
		if(x>=50000||x<=-50000||y>=50000||y<=-50000) dead=true;
	}
	if(dead) printf("DEAD");
	else printf("%d %d\n%c",x,y,op[dir]);
}
