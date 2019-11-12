#include<iostream>
#include<vector>
#include<set>
using namespace std;
int sud[101][9][9];
bool valid(int x){
	//for(int i=0;i<9;i++) for(int j=0;j<9;j++) if(sud[0][i][j]&&sud[0][i][j]!=sud[x][i][j]) return false;
	for(int i=0;i<9;i++){
		set<int> chkcol={},chkrow={};
		for(int j=0;j<9;j++) if(!chkcol.insert(sud[x][i][j]).second||!chkrow.insert(sud[x][j][i]).second) return false; // Check Row/Collumn
		if(*chkcol.begin()!=1||*--chkcol.end()!=9||*chkrow.begin()!=1||*--chkrow.end()!=9) return false; // Check 1-9
	}
	for(int i=0;i<9;i+=3) for(int j=0;j<9;j+=3){
		set<int> chkbox={};
		for(int k=0;k<3;k++) for(int l=0;l<3;l++) if(!chkbox.insert(sud[x][i+k][j+l]).second) return false;
	}
	return true;
}
int main(){
	int n; cin >> n;
	for(int k=0;k<=n;k++){
		for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin >> sud[k][i][j];
	}
	for(int i=1;i<=n;i++) if(valid(i)) cout << i << endl;
	cout << "END";
}
