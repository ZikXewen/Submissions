#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 5;
const int MXK = 1e6 + 5;
pair<int, int> b[MXK];
int m,n,k,mx,s,a[MXN],an,p;
void swap(int x,int y){
	if(x==p) p=y;
	else if(y==p) p=x;
	int tmp = a[x];
    a[x]=a[y];
    a[y]=tmp;
}
int main(){
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0, h, x; i < k; i++){
        scanf("%d %d", &x, &h);
        b[i] = {h, x - 1};
    }
    scanf("%d", &s); s--;
    sort(b, b + k);
    for(int i = k - 1; i >= 0; i--) swap(b[i].second, b[i].second+1);
    p = s; mx=a[s];
    an=max(an, (p? max(a[p+1],a[p-1]) : a[p+1]));
    for(int i=0;i<k;i++){
        swap(b[i].second,b[i].second+1);
        an=max(an, (p? max(a[p+1],a[p-1]) : a[p+1]));
    }
    if(mx>=an) printf("%d\nNO",mx);
    else printf("%d\nUSE",an);
}
