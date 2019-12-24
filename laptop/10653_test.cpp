#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int r,c; // Number of Rows, Number of Columns
int s1,s2,f1,f2; //Coordinates of Starting and Ending Points
bool v[1000][1000]; // List of Bomb/Passed Position in Each Row
int bfs(){
	queue<pair<pair<int,int>,int> > q; //Xpos,Ypos,CurrentTime
	q.push(make_pair(make_pair(s1,s2),0)); v[s1][s2]=true;
	while(!q.empty()){
		int x=q.front().first.first,y=q.front().first.second,z=q.front().second; //Queue Front
		//cout << x << " " << y << " " << z << endl;
		q.pop();
		if(x==f1&&y==f2) return z;
		if(y+1<c && !v[x][y+1]){ //Right
			v[x][y+1]=true;
			q.push(make_pair(make_pair(x,y+1),z+1));
		}
		if(y>0 && !v[x][y-1]){ //Left
			v[x][y-1]=true;
			q.push(make_pair(make_pair(x,y-1),z+1));
		}
		if(x+1<r && !v[x+1][y]){ //Down
			v[x+1][y]=true;
			q.push(make_pair(make_pair(x+1,y),z+1));
		}
		if(x>0 && !v[x-1][y]){ //Up
			v[x-1][y]=true;
			q.push(make_pair(make_pair(x-1,y),z+1));
		}
	}
	return -1;
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> r >> c && (r||c)){
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) v[i][j]=false;
		int a; // Rows with Bombs
		cin >> a;
		while(a--){
			int e,f; // Specific Row,Bombs in Row
			cin >> e >> f;
			while(f--){
				int tmp; // Bomb Position
				cin >> tmp;
				v[e][tmp]=true;
			}
		}
		cin >> s1 >> s2 >> f1 >> f2;
		cout << bfs() << endl;
	}
	//fclose(stdout);
}
