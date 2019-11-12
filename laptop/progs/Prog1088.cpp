#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> ma;
void mark(int p,int q){
	ma[p]=(ma[p]+1)%3;
	ma[q]=(ma[q]+2)%3;
}
int main(){
	int n,m,x,cur=0,ans=0; scanf("%d %d",&n,&m);
	ma[0]=0; ma[n]=0;
	for(int i=0;i<m;i++){
		int p,q; scanf("%d %d",&p,&q);
		mark(p-1,q);
	}
	char c; scanf(" %c",&c); if(c=='R') x=0;
	else if(c=='G') x=1; else x=2;
	map<int,int>::iterator it=ma.begin(),pv=ma.begin();
	while(++it!=ma.end()){
		cur=(cur+pv->second)%3;
		ans+=((it->first)-(pv->first))*((3+x-cur)%3);
		pv=it;
	}
	printf("%d",ans);
}

// R G G B G R    G		R G G B G G B	 G
// 0 1   1 2 2    4		0 1   1 2   1 2  5
// G B G	R
// 1 1 2 2  5
