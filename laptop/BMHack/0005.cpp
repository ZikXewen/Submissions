#include <bits/stdc++.h>
using namespace std;
string k, nos;
int d;
int main(){
	getline(cin, k);
	for(char i: k) if(i == '-') ++d;
	for(char i: k) if(i >= '0' and i <= '9') nos += i;
	if(nos.length() < 10){
		printf("Invalid : too short");
		return 0;
	}
	if(nos.length() > 10){
		printf("Invalid : too many digits");
		return 0;
	}
	if(nos[0] != '0' || (nos[1] != '1' && nos[1] != '5' && nos[1] != '6' && nos[1] != '8' && nos[1] != '9')){
		printf("Invalid : wrong prefix");
		return 0;
	}
	for(auto i: k) if((i < '0' || i > '9') && i != '-'){
		printf("Invalid : alphabetic");
		return 0;
	}
	for(int i = 1; i < k.length(); ++i) if(k[i] == '-' and k[i - 1] == '-') {
		printf("Invalid : two dashes together");
		return 0;
	}
	if(k[0] == '-' or k[1] == '-' or k.back() == '-'){
		printf("Invalid : wrong dash position");
		return 0;
	}
	if(d > 2){
		printf("Invalid : too many dashes");
		return 0;
	}
	printf("Valid");
}