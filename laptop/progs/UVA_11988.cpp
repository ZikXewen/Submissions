#include<iostream>
#include<list>
#include<string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("file.txt","w",stdout);
	string s; list<char> l; while(cin >> s){
		l.clear(); auto it=l.begin();
		for(char i:s){
			if(i=='[') it=l.begin();
			else if(i==']') it=l.end();
			else l.insert(it,i);
		}
		for(char i:l) cout << i; cout << endl;
	}
	//fclose(stdout);
}
