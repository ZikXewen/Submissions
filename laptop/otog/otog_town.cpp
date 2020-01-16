#include<iostream>
#define MAX 100001
using namespace std;
int p[MAX],h[MAX],n,m,q,a,b;
int fd(int x){
	if(p[x]==x) return x;
	return fd(p[x]);
}
void un(int st,int ed){
	int pw=fd(st),pu=fd(ed);
	if(pw==pu) return;
	if(h[pw]==h[pu]) {p[pw]=pu; h[pu]++;}
	else if(h[pw]>h[pu]) p[pu]=pw;
	else p[pw]=pu;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=1;i<=m;i++) p[i]=i;
	for(int i=0;i<n;i++){
		cin >> a >> b; un(a,b);
	}
	cin >> q; while(q--){
		cin >> a >> b;
		if(fd(a)==fd(b)) cout << "YES\n";
		else cout << "NO\n";
	}
}
