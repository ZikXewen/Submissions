#include<bits/stdc++.h>
using namespace std;
const int MXN = 	2e5+5; 
int N,fst1,fst2,ans; bool lv[MXN];
vector<int> ed1[MXN],ed2[MXN],st1,st2;
void inp(){
	int a,b;
	scanf("%d",&N);
	for(int i=0;i<(N<<1)-3;i++){
		scanf("%d%d",&a,&b);
		ed1[a].emplace_back(b); ed1[b].emplace_back(a);
		if(a>b) swap(a,b);
		if(a<=N&&lv[b]++) fst1=a;
	}
	memset(lv,0,sizeof lv);
	for(int i=0;i<(N<<1)-3;i++){
		scanf("%d%d",&a,&b);
		ed2[a].emplace_back(b); ed2[b].emplace_back(a);
		if(a>b) swap(a,b);
		if(a<=N&&lv[b]++) fst2=a;
	}
	//cout << fst1 << fst2 << endl;
	memset(lv,0,sizeof lv);
}
void trv(){
	queue<int> q; q.push(fst1); lv[fst1]++;
	while(!q.empty()){
		int x=q.front(); q.pop(); if(x<=N) st1.emplace_back(x);
		for(int i:ed1[x]) if(!lv[i]) lv[i]++,q.push(i);
	} memset(lv,0,sizeof lv);
	q.push(fst2); lv[fst2]++;
	while(!q.empty()){
		int x=q.front(); q.pop(); if(x<=N) st2.emplace_back(x);
		for(int i:ed2[x]) if(!lv[i]) lv[i]++,q.push(i);
	} memset(lv,0,sizeof lv);
}
void cmp(){
	int ct=0;
	if(st1[0]!=st2[0]) lv[st1[0]]++,lv[st2[0]]++,ct=2;
	for(int i=1;i<N-2;i++){
		if(st1[i]!=st2[i]){
			if(lv[st1[i]]) ct--; else ct++;
			if(lv[st2[i]]) ct--; else ct++;
			lv[st1[i]]=!lv[st1[i]];
			lv[st2[i]]=!lv[st2[i]];
		}
		if(!ct) ans++;
	} ct=0;	memset(lv,0,sizeof lv);
	if(st1[0]!=st2[N-1]) lv[st1[0]]++,lv[st2[N-1]]++,ct=2;
	for(int i=1;i<N-2;i++){
		if(st1[i]!=st2[N-i-1]){
			if(lv[st1[i]]) ct--; else ct++;
			if(lv[st2[N-i-1]]) ct--; else ct++;
			lv[st1[i]]=!lv[st1[i]];
			lv[st2[N-i-1]]=!lv[st2[N-i-1]];
		}			
		if(!ct) ans++;
	}
}
int main(){
	inp();
	trv();
	cmp();
	//cout << ans;
	cout << N-3-ans;
}
