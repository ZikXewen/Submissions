#include <iostream>
#include <vector>
using namespace std;
int a1,a2,a3;
bool sol(int a,int b,int c){
	for(int x=-100;x<22;x++){
		for(int y=x+1;y<100;y++){
			int z=a-x-y;
			if(z<=y) break;
			if(x*y*z==b && x*x+y*y+z*z==c){
				a1=x;a2=y;a3=z; return true;
			}
		}
	}
	return false;
}
int main (){
    int cas; cin >> cas;
    while(cas--){
    	int a,b,c; cin >> a >> b >> c;
    	if(sol(a,b,c)) cout << a1 << " " << a2 << " " << a3 << endl;
    	else cout << "No solution." << endl;
    }
    return 0;
}
