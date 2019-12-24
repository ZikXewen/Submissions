#include<utility>
#include<cstring>
#include<algorithm>
#define MXN 1000005
#define ii pair<int,int>
using namespace std;
ii qs[MXN];
int lt[MXN],ct=0,cl=1,N,K,S,E,lz[MXN],sg[MXN];
void dup(){
	int j=0;
	for(int i=1;i<cl;i++){
		if(lt[j]!=lt[i]) lt[++j]=lt[i];
	}
	cl=j+1;
}
int qr(int s, int e, int idx, ii x){
	if(lz[idx]){
		sg[idx]+=lz[idx];
		if(s!=e){
			lz[idx<<1]+=lz[idx];
			lz[idx<<1|1]+=lz[idx];
		}
		lz[idx]=0;
	}
	if(x.second<s||x.first>e) return -1;
	if(x.first<=s&&e<=x.second) return sg[idx];
	int m=(s+e)>>1;
	return max(qr(s,m,idx<<1,x),qr(m+1,e,idx<<1|1,x));
}
void ud(int s,int e,int idx,ii x){
	if(s>e) return;
	if(lz[idx]){
		sg[idx]+=lz[idx];
		if(s!=e){
			lz[idx<<1]+=lz[idx];
			lz[idx<<1|1]+=lz[idx];
		}
		lz[idx]=0;
	}
	if(x.second<s||x.first>e) return;
	if(x.first<=s&&e<=x.second){
		sg[idx]++;
		if(s!=e) {lz[idx<<1]++; lz[idx<<1|1]++;}
		return;
	}
	int m=(s+e)>>1;
	ud(s,m,idx<<1,x); ud(m+1,e,idx<<1|1,x);
	sg[idx]=max(sg[idx<<1],sg[idx<<1|1]);
}
int main(){
	scanf("%d%d",&N,&K);
	while(N--){
		scanf("%d%d",&S,&E);
		lt[cl++]=S; lt[cl++]=E;
		qs[ct++]={S,E};
	}
	sort(lt,lt+cl);
	dup();
	for(int j=0;j<ct;j++){
		ii i=qs[j];
		i.first=lower_bound(lt,lt+cl,i.first)-lt; 
		i.second=lower_bound(lt,lt+cl,i.second)-lt;
		if(qr(1,cl,1,i)<K){
			printf("yes\n");
			ud(1,cl,1,i);
		}
		else printf("no\n");
	}
}
