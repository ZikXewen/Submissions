#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
vector<string> grid;
int vis[100][100],r,cl;
int dfs(int x,int y){
	if(x>=r||y>=cl||x<0||y<0) return 0;
	if(vis[x][y]) return 0;
	vis[x][y]=1;
	if(grid[x][y]=='L') return 0;
	return dfs(x+1,y)+dfs(x,y+1)+dfs(x-1,y)+dfs(x,y-1)+dfs(x+1,y+1)+dfs(x+1,y-1)+dfs(x-1,y-1)+dfs(x-1,y+1)+1;
}
int main(){
	//freopen("file.txt","w",stdout);
	int c;
	cin >> c;
	scanf("\n");
	while(c--){
		grid.clear();
		string inp;
		while(getline(cin,inp) && inp.length()){
			if(inp[0]=='L'||inp[0]=='W'){
				grid.push_back(inp);
			}
			else{
				cl=grid[0].length();
				r=grid.size();
				memset(vis,0,sizeof(vis));
				int x,y;
				const char* ch=inp.c_str();
				sscanf(ch,"%d %d",&x,&y);
				cout << dfs(--x,--y) << endl;
			}
		}
		if(c)cout << endl;
	}
//	fclose(stdout);
}
