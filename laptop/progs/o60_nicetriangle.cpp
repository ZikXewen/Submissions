#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MXN = 400 , MOD = 29947;
int mm[MXN][MXN][MXN];
void f(int &a, int &b, int &c) {
	if(a<b) swap(a, b);
	if(b<c) swap(b, c);
	if(a<b) swap(a, b);
}
int dp(int a, int b, int c) {
	f(a, b, c);
	if(mm[a][b][c]!=-1) return mm[a][b][c];
	if(!a && !b && !c) return mm[a][b][c]=1;
	mm[a][b][c]=dp(a-1, b, c);
	for(int i=1; i<=b;++i) mm[a][b][c]=(mm[a][b][c]+dp(a-1, b-i, c))%MOD;
	for(int i=1;i<=c;++i) mm[a][b][c]=(mm[a][b][c]+(dp(b, i-1, 0)*dp(a-1, c-i, 0)))%MOD;
	return mm[a][b][c];
}
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	memset(mm,-1,sizeof mm);
	printf("%d\n",dp(a-1,b-1,c-1));
}
