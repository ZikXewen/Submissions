#include<cstdio>
#include<set>
#include<map>
#define MXQ 200005
using namespace std;
set<int> s;
map<int,int> m;
int ft[MXQ],q,x[MXQ],n,M[MXQ],cnt;
char c[MXQ];
void ud(int idx,int val){
	for(;idx<=n;idx+=-idx&idx) ft[idx]+=val;
}
int qr(int idx){
	int ret=0;
	for(;idx>0;idx-=-idx&idx) ret+=ft[idx];
	return ret;
}
int bs(int s,int e,int x){
    if(s>=e)    return M[s];
    int m=(s+e)>>1;
    if(qr(m)<x) return bs(m+1,e,x);
    return bs(s,m,x);
}
bool ck(int x){
	return qr(x)-qr(x-1);
}
int main(){
	scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf(" %c %d",&c[i],&x[i]);
        s.insert(x[i]);
    }
    for(auto i:s){
       	m[i]=++n; M[n]=i;
	}
	for(int i=0;i<q;i++){
		int l=m[x[i]];
		if(c[i]=='I') if(!ck(l)) {ud(l,1); cnt++;}
		if(c[i]=='D') if(ck(l)) {ud(l,-1); cnt--;}
		if(c[i]=='K'){
			if(cnt<x[i]) printf("invalid\n");
			else printf("%d\n",bs(1,n,x[i]));
		}
		if(c[i]=='C') printf("%d\n",qr(l-1));
	}
}
