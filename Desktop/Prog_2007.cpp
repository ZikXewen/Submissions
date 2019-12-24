#include<bits/stdc++.h>
using namespace std;
int g,s,cur[55],neg,ans;
char w[3005],str[3000005];
int idx(char in){
	if(in<'a') return in-'A';
	return in-'a'+26;
}
int main(){
	scanf("%d%d",&g,&s);
	scanf(" %s %s",w,str);
	for(int i=0;i<g;i++) cur[idx(w[i])]++;
	for(int i=0;i<g;i++) if(--cur[idx(str[i])]==-1) neg++; if(!neg) ans++;
	for(int i=g;i<s;i++){
		if(++cur[idx(str[i-g])]==0) neg--;
		if(--cur[idx(str[i])]==-1) neg++;
		if(!neg) ans++;
	}
	printf("%d",ans);
}
