#include<stdio.h>
int hammingDistance(int x, int y) {
	int a=0	;
	while(y!=0||x!=0){ 
		if(x%2!=y%2){
			a++;
		}
		x=(x-(x%2))/2;
		y=(y-(y%2))/2;
	}
	return a;
}
int main(){
	int a=1,b=4;
	printf("%d",hammingDistance(a,b));
}
