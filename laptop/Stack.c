#include<stdio.h>
int top=0,i;
char dat[15],in[15],p;
void push(char a){
	dat[top]=a; top++;
}
char pop(){
	return dat[--top];
}
int main(){
	scanf("%s",in);
	for(i=0;in[i]!='\0';i++){
		if(in[i]=='('||in[i]=='[') push(in[i]);
		else{
			p=pop();
			if((in[i]==')'&&p=='(')||(in[i]==']'&&p=='['));
			else {
				printf("WRONG"); return 0;
			}
		}
	}
	printf("CORRECT");
	return 0;
}
