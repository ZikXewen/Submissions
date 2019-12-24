#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,R,a,ct=1;
vector<int> s;
int main(){
	scanf("%d%d",&N,&R); R--;
	for(int i=0;i<N;i++) {scanf("%d",&a); if(a) s.push_back(i-R);} R<<=1; 
	auto x=upper_bound(s.begin(),s.end(),0);
	if(x==s.begin()){
		printf("-1"); return 0;	
	}x--;N--;
	while(1){ 
		auto tem=upper_bound(s.begin(),s.end(),*x+R+1)-1;
		if(*x+R>=N) break;
		if(tem==x){
			printf("-1"); return 0;
		}
		x=tem; ct++; 
	}
	printf("%d",ct);
}
