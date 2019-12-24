#include<iostream>
#define MXN 1000000
using namespace std;
int ft[3][MXN+5],cur[MXN+5],n,m,a,b,d;
char c;
void mk(int t,int idx){
	for(;idx<=MXN;idx+=-idx&idx) ft[t][idx]++;
}
void rm(int t,int idx){
	for(;idx<=MXN;idx+=-idx&idx) ft[t][idx]--;
}
int qr(int t,int idx){
	int sum=0;
	for(;idx>0;idx-=-idx&idx) sum+=ft[t][idx];
	return sum;
}
void Init(){
	for(int i=1;i<=MXN;i++){
		mk((i-1)%3,i);
		cur[i]=(i-1)%3;
	}
}
int main(){
	Init();
	cin >> n >> m;
	while(m--){
		cin >> a;
		if(a==1){
			cin >> b >> c;
			rm(cur[b],b);
			switch(c){
				case 'R' : mk(0,b); cur[b]=0; break;
				case 'G' : mk(1,b); cur[b]=1; break;
				default : mk(2,b); cur[b]=2;
			}
		}
		else{
			cin >> b >> d;
			int ret=-1,typ; bool X=false;
			for(int i=0;i<3;i++){
				if(qr(i,d)-qr(i,b-1)>ret){
					ret=qr(i,d)-qr(i,b-1);
					typ=i;
				}
			}
			for(int i=typ+1;i<3;i++) if(qr(i,d)-qr(i,b-1)==ret){
				cout << "None\n"; X=true; break;
			}
			if(!X) 	switch(typ){
				case 0 : cout << "R\n"; break;
				case 1 : cout << "G\n"; break;
				default: cout << "B\n";
			}
		}
	}
}
