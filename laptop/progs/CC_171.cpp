#include<cstdio>
#include<iostream>
#include<string>
#define MXN 1200010
#define INF 1 << 30
using namespace std;
int st[MXN],qs[MXN];
string s; int n,ct=1,S,E;
void bd(int s,int e,int idx){
	if(s==e){st[idx]=qs[s]; return;}
	int m=(s+e)/2;
	bd(s,m,idx<<1);
	bd(m+1,e,idx<<1|1);
	st[idx]=min(st[idx<<1],st[idx<<1|1]);
}
int qr(int s,int e,int idx){
	if(E<s||S>e) return INF;
	if(s>=S&&e<=E) return st[idx];
	int m=(s+e)/2;
	return min(qr(s,m,idx<<1),qr(m+1,e,idx<<1|1));
}
int main(){
	cin >> s; scanf("%d",&n);
	for(char i:s){
		if(i=='(') qs[ct]=qs[ct-1]+1;
		else qs[ct]=qs[ct-1]-1;
		ct++;
	}
	for(char i:s){
		if(i=='(') qs[ct]=qs[ct-1]+1;
		else qs[ct]=qs[ct-1]-1;
		ct++;
	}
	bd(1,ct,1);
	while(n--){
		scanf("%d%d",&S,&E);
		if(E<S) E+=ct>>1;
		if(qs[S-1]==qs[E]&&qr(1,ct,1)-qs[S-1]>=0) printf("yes\n");
		else printf("no\n");
	}
}
