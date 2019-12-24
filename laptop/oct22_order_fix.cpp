#include<cstdio>
#include<algorithm>
#include<map>
#define ii pair<int,int>
#define MXN 1005
using namespace std;
int N,post[MXN],pre[MXN];
map<int,pair<int,int>> m;
void rec(int *s1,int *e1,int *s2,int *e2){//printf("%d %d %d %d\n",*s1,*e1,*s2,*e2);
	if(e1-s1<=1) return;
	if(*(s1+1)==*(s2+1)){
		m[*s1]={*(s1+1),0}; rec(s1+1,e1,s2+1,e2);
		return;
	}
	int *m1=find(s1,e1,*(s2+1));
	int *m2=find(s2,e2,*(s1+1));
	m[*s1]={*(s1+1),*m1};
	rec(s1+1,m1,m2,e2); rec(m1,e1,s2+1,m2);
}
void inorder(int cur){
	ii x=m[cur];
	if(x.first) inorder(x.first);
	printf("%d\n",cur);
	if(x.second) inorder(x.second);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&pre[i]);
	for(int i=N;i>0;i--) scanf("%d",&post[i]);
	rec(pre+1,pre+N+1,post+1,post+N+1);
	inorder(pre[1]);
}