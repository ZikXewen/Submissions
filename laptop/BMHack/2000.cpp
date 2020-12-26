#include <bits/stdc++.h>
using namespace std;
string l;
int k;
map<char, int> code;
int main(){
    code['c'] = 500;
    code['C'] = 500;
    code['e'] = 5;
    code['E'] = 5;
    code['k'] = 2;
    code['K'] = 2;
    code['m'] = 3;
    code['M'] = 3;
    code['p'] = 40;
    code['P'] = 40;
    code['t'] = 1000;
    code['T'] = 1000;
    code['u'] = 15;
    code['U'] = 15;
    code['-'] = -2;
    getline(cin, l);
    for(auto i: l) k += code[i];
    cout << k;
}