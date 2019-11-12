#include<iostream>
using namespace std;
int n,t1,t2,mi[31],ar1[31][31],ar2[31][31];
pair<int,pair<int,int> > mem[31][300][300];
pair<int,pair<int,int> > dp(int sit,int a,int b){
	pair<int,int> x;
	if(a==0&&b==0) return make_pair(0,make_pair(-1,-1));
	if(mem[sit][a][b].first!=-1) return mem[sit][a][b];
	int mn=60001;
	for(int i=0;i<=mi[sit]&&a-i>=0;i++){
		if(b-mi[sit]+i<0) continue;
		if(mn>dp(sit+1,a-i,b-mi[sit]+i).first+ar1[sit][i-1]+ar2[sit][mi[sit]-i-1]){
			mn=dp(sit+1,a-i,b-mi[sit]+i).first+ar1[sit][i-1]+ar2[sit][mi[sit]-i-1];
			x=make_pair(a-i,b-mi[sit]+i);
		}
	}
	return mem[sit][a][b]=make_pair(mn,x);
}
int main(){ //freopen("file.txt","w",stdout);
	while(cin >> t1 >> t2 && (t1||t2)){
		cin >> n;
		for(int i=0;i<n;i++) for(int j=0;j<=t1;j++) for(int k=0;k<=t2;k++) mem[i][j][k]=make_pair(-1,make_pair(-1,-1));
		for(int i=0;i<n;i++){
			cin >> mi[i];
			for(int j=0;j<mi[i];j++) cin >> ar1[i][j];
			for(int j=0;j<mi[i];j++) cin >> ar2[i][j];
		}
		cout << dp(0,t1,t2).first << endl;
		pair<int,int> x=dp(0,t1,t2).second,cur=make_pair(t1,t2); int ct=0;
		while(x!=make_pair(-1,-1)){
			if(ct) cout<<" ";
			cout << cur.first-x.first; 
			cur=x; x=dp(++ct,x.first,x.second).second;
		} cout << endl << endl;
	}
	//fclose(stdout);
}
