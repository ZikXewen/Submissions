#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e6+5;
int n[2],l,q,cur[mxn],ft[2][mxn];
bool id[mxn]; //is down?
void ud(int typ,int x,int xx){for(;x<=l;x+=-x&x) ft[typ][x]+=xx;}
int gt(int typ,int x){int ret=0; for(;x;x-=-x&x) ret+=ft[typ][x]; return ret;}
int main(){
	scanf("%d%d%d",&n[0],&l,&q);
	ud(0,l,n[0]);
	for(int i=0;i<n[0];i++) cur[i]=l;
	for(int i=0,typ,t1,t2;i<n;i++){
		scanf(" %c",&typ);
		if(typ == 's'){
			scanf(" %d%d",&t1,&t2);
			ud(id[t1],cur[t1],-1);
			cur[t1]=(cur[t1]+t2)%l; if(!cur[t1]) cur[t1]=l;
			ud(id[t1],cur[t1],1);
		}
		else if(typ == 'q'){
			scanf(" %d",&t1);
		}
		else {
			scanf(" %d",&t1);
			ud(id[t1],cur[t1],-1); n[id[t1]]--;
			id[t1]=!id[t1];
			ud(id[t1],cur[t1],1); n[id[t1]]++;
		}
	}
	cout << ;
}
