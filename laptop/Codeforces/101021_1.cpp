#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int l = 1, r = 1e6;
    string in;
    while(l < r){
        int m = (l + r + 1) >> 1;
        cout << m << endl;
        cin >> in;
        if(in[0] == '<') r = m - 1;
        else l = m;
    }
    cout << "! " << r << endl;
}