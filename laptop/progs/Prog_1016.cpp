#include<cstdio>
#include<cmath>
#include<cstring>
#define SQRTTWO 0.70710678118
using namespace std;
int toi(char s[6],int dir){
	int ret=0;
	for(int i=0;i<dir;i++) ret=10*ret+s[i]-48;
	return ret;
}
int main(){
	double x=0,y=0;
	while(1){
		char s[6]; scanf("%s",s); if(s[0]=='*') break;
		int dir=strlen(s)-1; if(s[dir-1]>'A') dir--; int dis=toi(s,dir);
		switch(s[dir]){
		case 'N' : if(s[dir+1]){
						y+=SQRTTWO*dis;
						if(s[dir+1]=='E') x+=SQRTTWO*dis;
						else x-=SQRTTWO*dis;
					}
					else y+=dis; break;
		case 'E' : x+=dis; break;
		case 'S' : if(s[dir+1]){
						y-=SQRTTWO*dis;
						if(s[dir+1]=='E') x+=SQRTTWO*dis;
						else x-=SQRTTWO*dis;
					}
					else y-=dis; break;
		default  : x-=dis;
		}
	}
	printf("%.3lf %.3lf\n%.3lf",x,y,sqrt((x*x)+(y*y)));
}
