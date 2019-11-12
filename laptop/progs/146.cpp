#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
bool fnct(){
	if(s.length()==1) return false;
	auto it=s.end()-1; // Back-1
	while(--it!=s.begin()-1){
		auto it2=s.end(); // Back
		while(--it2!=it){
			if(*it<*it2){
				swap(*it,*it2);
				reverse(it+1,s.end());
				return true;
			}
		}
	}
	return false;
}
int main(){
	//freopen("file.txt","w",stdout);
	while(cin >> s && s!="#"){
		if(fnct()) cout << s << endl;
		else cout << "No Successor" << endl;
	}
	//fclose(stdout);
}
