#include<iostream>
#include<string>
#include<set>
using namespace std;
bool pal(string s){
	auto st = s.begin(),ed = s.end(); st--;
	while(++st<--ed) if(*st!=*ed) return false;
	return true;
}
int main(){
	//freopen("file.txt","w",stdout);
	string s; set<string> se; while(cin >> s){
		se.clear();
		for(int i=0;i<s.length();i++){
			for(int j=1;j<=s.length()-i;j++){
				string ss=s.substr(i,j);
				if(pal(ss)) se.insert(ss);
			}
		}
		cout << "The string \'" << s << "\' contains " << se.size() << " palindromes.\n";
	}
	//fclose(stdout);
}
