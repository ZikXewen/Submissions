#include<stdio.h>
int main(){
	int ch;
	long n,i;
	scanf("%ld",&n);
	long long a[n],t,run;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n;i++){
		ch=0; t=a[i]+1;
		while(t%2==0&&t!=1)
			t/=2;
		if(t!=1) printf("NO\n");
		else{
			for(run=2;run*run<=a[i];++run){
				if(a[i]%run==0) {
					ch=1;
					break;
				}
			}
			if(a[i]==1||ch==0) printf("NO\n");
			else printf("YES\n");
		}
	}
}
