#include<iostream>
#include<string>
using namespace std;
int main(){
	string inp;
	int cs;
	cin >> inp >> cs;
	while(cs--){
		int st,ed,ad=0;
		bool ck = true;
		string str;
		cin >> str;
		for(int ct=0;ct<str.length()&&ck;ct++){
			while(str[ct]!=inp[ad]) {
				ad++;
				if(inp.begin()+ad==inp.end()){
					cout << "Not matched\n";
					ck = false;
					break;
				}
			}
			if(ct==0) st=ad;
			if(ct==str.length()-1) ed=ad;
			ad++;
		}
		if(ck){
			cout << "Matched " << st << " " << ed << endl;
		}
	}
	return 0;
}
