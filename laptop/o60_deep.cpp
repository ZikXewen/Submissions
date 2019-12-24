#include <cstdio>
#include <vector>
#define MXN 200005
#define ii pair<int,int>
using namespace std;
class node{
public:
	node* l=NULL,*r=NULL;
	vector<int> in;
};
int N,Q,L,s,a,b;
ii v[MXN];
node* root=new node;
void bd(node *cur,int no){
	 cur->in.emplace_back(no);
	 if(v[no].first==-1&&v[no].second==-1) return;
	 if(v[no].first!=-1&&v[no].second!=-1){
	 	cur->l = new node;
	 	cur->r = new node;
	 	bd(cur->l,v[no].first); bd(cur->r,v[no].second);
	 	return;
	}
	 if(v[no].first==-1) bd(cur,v[no].second);
	 else bd(cur,v[no].first);
}
int dir(){
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
 	return res;
}
int dfs(node *cur,int lft){// printf("%d ",cur->in.size());
	if(lft<cur->in.size()) return cur->in[lft];
	if(cur->l==NULL) return cur->in.back();
	if(dir()) return dfs(cur->r,lft-cur->in.size());
	return dfs(cur->l,lft-cur->in.size());
}
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++) {scanf("%d%d",&v[i].first,&v[i].second);}
	bd(root,0);
	while(Q--){ 
		scanf("%d%d%d%d",&L,&s,&a,&b);
		printf("%d\n",dfs(root,L));
	}
}
