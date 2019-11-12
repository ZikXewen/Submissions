#include<stdio.h>
int dat[30],front=0,back=0;
void push(int a){
	dat[back++]=a;
}
int pop(){
	return dat[front++];
}
int main(){
	push(6);
	push(7);
	printf("%d",pop());
	push(4);
	printf("%d",pop());
	printf("%d",pop());
	push(5);
	printf("%d",pop());  
	return 0;
}
