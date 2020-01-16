#include<iostream>
#include<map>
using namespace std;
map<char,int> m;
int main(){
	char cmd,cmd2;
	while(cin >> cmd ){
		switch(cmd){
			case '=' : cin >> cmd; cin >> m[cmd]; break;
			case '#' : cin >> cmd; cout << m[cmd] << endl; break;
			case '+' : cin >> cmd >> cmd2; m[cmd]+=m[cmd2]; break;
			case '-' : cin >> cmd >> cmd2; m[cmd]-=m[cmd2]; break;
			case '*' : cin >> cmd >> cmd2; m[cmd]*=m[cmd2]; break;
			case '/' : cin >> cmd >> cmd2; m[cmd]/=m[cmd2]; break;
			case '!' : cout << "!"; return 0;
		}
	}
}
