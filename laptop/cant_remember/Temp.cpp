#include<cstdio>
#include<iostream>
#include<algorithm>
#define MXN 300005
using namespace std;
class trip{
	public:
		int typ,st,ed;
};
int N,Q,S,E,tem,CMD,iq=0,ic=1,cpy[MXN],ft[MXN];
trip qs[MXN];
void mk(int s,int e){
	s=lower_bound(cpy,cpy+ic,s)-cpy;
	e=lower_bound(cpy,cpy+ic,e)-cpy;
	for(;s<=ic;s+=-s&s) ft[s]++;
	for(;e<=ic;e+=-e&e) ft[e]--;
}
int qr(int ind){
	int ret=0;
	ind=upper_bound(cpy,cpy+ic,ind)-cpy-1;
	if(ind<=0) return 0;
	for(;ind>0;ind-=-ind&ind) ret+=ft[ind];
	return ret;
}
void Dup(){
    int j=0;
    for(int i=1;i<ic;i++){
        if(cpy[i]!=cpy[j]) cpy[++j]=cpy[i];
    }
    ic=j+1;
}
int main(){
	scanf("%d%d",&N,&Q);
	while(Q--){
		scanf("%d",&CMD);
		if(CMD==1){
			scanf("%d%d",&S,&E);
			cpy[ic++]=S; cpy[ic++]=++E;
		}
		else scanf("%d",&S);
		qs[iq++]={CMD,S,E};
		
	}
	sort(cpy,cpy+ic);
	Dup();
	for(int j=0;j<iq;j++){ 
		trip i=qs[j];
		if(i.typ) mk(i.st,i.ed);
		else{
			tem=qr(i.st);
			if(!(tem%6)) printf("sleep\n");
			else if(tem%2) printf("eat\n");
			else printf("work\n");
		}
	}
}/*
10 8
1 1 2
1 7 10
1 3 9
0 3
1 4 9
0 4
1 3 4
0 7*/
