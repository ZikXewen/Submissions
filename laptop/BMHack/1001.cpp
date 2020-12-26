#include <bits/stdc++.h>
using namespace std;
string in;
int sm;
bool comp(string x){
    reverse(x.begin(), x.end());
    if(in.length() < x.length()) return 0;
    for(int i = 0; i < x.length(); ++i) if(in[i] != x[i]) return 0;
    return 1;
}
int val(int x){
    if(in[x] == 'C') return 12;
    else if(in[x] == 'O') return 16;
    else if(in[x] == 'H') return 1;
    else if(in[x] == 'N') return 14;
    return val(x - 1) * (in[x] - '1');
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> in;
    for(int i = 0; i < in.length(); ++i) sm += val(i);
    cout << sm << "\nThis compound is ";
    reverse(in.begin(), in.end());
    if(comp("CONH2")) return cout << "amide", 0;
    if(comp("NH2")) return cout << "amine", 0;
    if(comp("COOH")) return cout << "carboxylic acid", 0;
    if(comp("CHO")) return cout << "aldehyde", 0;
    if(comp("OH")) return cout << "alcohol", 0;
    if(in.find("OOC") != string::npos) return cout << "ester", 0;
    if(in.find("OC") != string::npos) return cout << "ketone", 0;
    if(in.find("O") != string::npos) return cout << "ether", 0;
    assert(0);
}