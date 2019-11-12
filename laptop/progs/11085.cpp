#include<iostream>
#include<algorithm>
using namespace std;
int in[8],ans[8];
int finddif(){
	int ret=0;
	for(int i=0;i<8;i++) if(ans[i]!=in[i]) ret++;
	return ret;
}
bool ckdiag(){
	for(int i=0;i<7;i++) for(int j=i+1;j<8;j++) if(abs(ans[i]-ans[j])==abs(i-j)) return false;
	return true;
}
int main(){
	int cs=1;
//	freopen("file.txt","w",stdout);
	while(cin >> in[0]){
		int mn=8;
		for(int i=1;i<8;i++) cin >> in[i];
		for(int i=0;i<8;i++) {
			in[i]--; ans[i]=i;
		}
		do if(ckdiag()){
			mn=min(mn,finddif());
			//for(int i:ans) cout << i << " "; cout << finddif() << endl;
		}
		while(next_permutation(ans,ans+8));
		cout << "Case " << cs++ << ": " << mn << endl;
	}
//	fclose(stdout);
}
