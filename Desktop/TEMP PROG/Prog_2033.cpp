#include<bits/stdc++.h>
#define MXN 2010
using namespace std;

class person{ public: int id,sco,ct; };
bool comp(person L,person R){
	if(L.sco!=R.sco) return L.sco>R.sco;
	if(L.ct!=R.ct) return L.ct>R.ct;
	return L.id<R.id;
}

bool tab[MXN][MXN];
int N,T,P;
int qua[MXN];
person in[MXN];

int main(){
	scanf("%d%d%d",&N,&T,&P);
	for(int i=1;i<=T;i++) qua[i]=N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=T;j++){
			scanf("%d",&tab[i][j]);
			in[i].ct+=tab[i][j];
			in[i].id=i;
			qua[j]-=tab[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=T;j++){
			in[i].sco+=tab[i][j]*qua[j];
		}
	}
	sort(&in[1],&in[N+1],comp);
	for(int i=1;i<=N;i++) if(in[i].id==P) printf("%d %d",in[i].sco,i);
}