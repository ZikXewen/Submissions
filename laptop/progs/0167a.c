#include<stdio.h>
int checkprime(long long a){
	long i;
	if(a==1) return 0;
	for(i=2;i*i<=a;i++){
		if(a%i==0){
			return 0;
		}
	} 
	return 1;
}
int checkpow(long long a){
	int ch=0; long long c=a+1;
	while(c%2==0) c/=2;
	if(c==1) ch=1;
	return ch;
}
int main(){
	long i,q; scanf("%ld",&q);
	long long n[q];
	for(i=0;i<q;i++) scanf("%lld",&n[i]);
	for(i=0;i<q;i++){
		if(checkpow(n[i])) printf("YES\n"); 
		else if(checkprime(n[i])) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
