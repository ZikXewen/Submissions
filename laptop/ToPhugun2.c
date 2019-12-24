#include<stdio.h>
int i,t,ct[10];
main(){
	for(i=1;i<=500;i++){
		t=i;
		do ct[t%10]++; while(t/=10);
	}
	for(i=0;i<10;i++) printf("%d\n",ct[i]);
}
