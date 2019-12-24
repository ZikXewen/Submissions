#include<iostream>
using namespace std;
int n,ar[20],bit,m,mx,mxans;
void recurse(int cur,int sm,int bit){
	if(sm>m) return;
	if(cur==n) {if(sm<=m&&sm>mx){mx=sm; mxans=bit;} return;}
	recurse(cur+1,sm+ar[cur],bit+(1<<cur));
	recurse(cur+1,sm,bit);
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> m){ mx=0;
		cin >> n; for(int i=0;i<n;i++) cin >> ar[i];
		recurse(0,0,0);
		for(int i=0;i<n;i++){
			if((1<<i) > mxans) break;
			if((1<<i)&mxans) cout << ar[i] << " ";
		} 
		cout << "sum:" << mx <<endl;
	}
	//fclose(stdout);
}
