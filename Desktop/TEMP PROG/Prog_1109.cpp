#include<cstdio>
#include<algorithm>
#define ii pair<int,int>
#define MXN 100005
using namespace std;
ii v[MXN],t[MXN]; int N;
double mrg(int s,int e){
	if(s==e) return 0;
	int m=(s+e)>>1,i=s,j=m+1,k=s;
	double ret=mrg(s,m)+mrg(m+1,e),ct=0;
	while(i<=m&&j<=e){
		if(v[i].second<=v[j].second){
			ret+=ct*v[i].first; //printf("%.0lf ",ret);
			t[k++]=v[i++];
		}
		else{
			++ct;
			ret+=double(m-i+1)*v[j].first; //printf("%.0lf ",ret);
			t[k++]=v[j++];
		}
	}
	while(i<=m){
		ret+=ct*v[i].first; //printf("%.0lf ",ret);
		t[k++]=v[i++];
	}
	while(--k>=s) v[k]=t[k]; //printf("%d %.0lf\n",ct,ret);
	return ret;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",&v[i].first,&v[i].second);
	sort(v,v+N);
	//for(int i=0;i<N;i++) printf("%d %d\n",v[i].first,v[i].second);
	printf("%.0lf",mrg(0,N-1));
	//for(int i=0;i<N;i++) printf("%d %d\n",v[i].first,v[i].second);
}
