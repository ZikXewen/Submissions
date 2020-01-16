#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int cap,tim,m;
queue<int> l[2];
void gos(int& cur,int& cub){ // Current Time & Current Base
	int i=0;
	while(i<=cap&&l[cub].front()<=cur&&!l[cub].empty()){
		l[cub].pop(); i++;
	}
	if(i>cap) i--;
	cur+=tim; cub=(cub+1)%2;
	while(i--) cout << cur << endl;
}
void ferr(){
	int cur=0; int cub=0; //Departing Time, Current Base
	while(!l[0].empty()||!l[1].empty()){
		int tep=(cub+1)%2; // Incurrent Base
		if(l[cub].front()<=cur&&!l[cub].empty()){ // Already Waiting Cars
			//cout << "x ";
			gos(cur,cub);
		}
		else if((l[cub].front()>l[tep].front()||l[cub].empty())&&!l[tep].empty()){ // No Waiting Cars & New Car Arrived at Another Side
			cur=max(cur,l[tep].front())+tim;
			//cout << cur << " o ";
			gos(cur,tep); 
		}
		else{ // No Waiting Cars & New Car Arrived at This Side
			cur=max(cur,l[cub].front());
			//cout << "- ";
			gos(cur,cub);
		}
	}
}
int main(){
	//freopen("file.txt","w",stdout);
	int ca; cin >> ca;
	while(ca--){
		cin >> cap >> tim >> m;
		for(int i=0;i<m;i++){
			string s; int tem;
			cin >> tem >> s;
			if(s=="left") l[0].push(tem);
			else l[1].push(tem);
		}
		ferr();
		if(ca) cout << endl;
	}
	//fclose(stdout);
}
