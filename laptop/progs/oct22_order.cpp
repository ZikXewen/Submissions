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
/*
11
1 2 3 4 5 6 7 8 9 10 11
4 3 6 7 5 2 10 11 9 8 1
-> 4 3 2 6 5 7 1 10 9 11 8

7
1 2 3 4 5 6 7
3 6 7 5 4 2 1
-> 3 2 6 5 7 4 1

16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4 6 5 3 8 7 2 10 14 13 16 15 12 11 9 1
-> 4 3 6 5 2 8 7 1 10 9 14 13 12 16 15 11
*/
