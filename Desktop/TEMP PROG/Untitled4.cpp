#include<cstdio>
#include<algorithm>
#define MXN 200010
using namespace std;
int N,M,Q,A,v[MXN],q;
void del(){
	int j=0,ct=0;
	for(int i=1;i<M;i++){
		if(v[j]!=v[i]){
			if(ct&1) j--;
			v[++j]=v[i];
			ct=0;
		}
		else ct++;
	}
	M=j+1;
}
int main(){
	scanf("%d%d%d",&N,&M,&Q); M<<=1;
	for(int i=0;i<M;i+=2) {scanf("%d%d",&v[i],&A); v[i+1]=v[i]+A;}
	sort(v,v+M); del();
	//for(int i=0;i<M;i++) printf("%d ",v[i]);
	while(Q--){
		scanf("%d",&q);
		auto it=upper_bound(v,v+M,q);
		if(it==v) printf("%d\n",*it-1);
		else if(it==v+M) printf("%d\n",N+1-*(it-1));
		else printf("%d\n",*it-*(it-1));
	}
}
