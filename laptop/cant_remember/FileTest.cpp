#include <bits/stdc++.h>
using namespace std;
int main(){
    // string fnm;
    // cin >> fnm;

    ifstream inp("File.txt");
    ofstream tmp("__Temp.txt", ios::trunc);

    string ol, nw;
    cout << "Replaced Term: "; cin >> ol;
    cout << "Replacing Term: "; cin >> nw;

    string tms;
    while(inp >> tms)
        tmp << ((tms == ol)? nw : tms) << '\n';

    inp.close(); tmp.close();
    remove("File.txt");
    rename("__Temp.txt", "File.txt");
}