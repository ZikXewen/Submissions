#include<iostream>
#include<cstring>
using namespace std;
int n,m,ar[20],sm;
bool mem[1<<20];
bool srh(int len,int btmk){
	if(mem[btmk]) return false;
	if(len>sm/4) return false;
	if(len==sm/4){
		if(btmk==(1<<m)-1) return true;
		len=0;
	}
	for(int i=0;i<m;i++) if(!(btmk&1<<i)&&srh(len+ar[i],btmk|1<<i)) return true;
	mem[btmk]=true;
	return false;
}
bool ck(){
	if(sm%4) return 0;
	memset(mem,false,sizeof mem);
	return srh(0,0);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	while(n--){
		cin >> m; sm=0;
		for(int i=0;i<m;i++){
			cin >> ar[i];
			sm+=ar[i];
		}
		cout << (ck()? "yes":"no") << endl;
	}
}
