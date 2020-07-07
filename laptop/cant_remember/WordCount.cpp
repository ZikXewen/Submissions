#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("File.txt");
    string tmp; int ct = 0;
    
    while(inp >> tmp) ++ct;
    cout << "File.txt has " << ct << " words\n";
    inp.close();
    inp.open("File.txt");
    ct = 0;

    while(getline(inp, tmp)) ++ct;
    cout << "File.txt has " << ct << " lines";
}