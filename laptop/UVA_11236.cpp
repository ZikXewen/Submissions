#include<cstdio>
using namespace std;
int main(){
	//freopen("file.txt","w",stdout);
	for(int a=1;4*a<=2000;a++){
		for(int b=a;b+3*a<=2000;b++){
			for(int c=b;a+b+c+c<=2000;c++){
				long long p = (long long) a * b * c;
       			long long s = a + b + c;
        		if (p <= 1000000) continue;
       			if ((s * 1000000)%(p - 1000000)) continue;
		        int d = (s * 1000000) / (p - 1000000);
        		s += d;
        		if (s > 2000 || d < c)   continue;
        		printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
			}
		}
	}
	//fclose(stdout);
}
