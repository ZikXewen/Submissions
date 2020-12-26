#include <bits/stdc++.h>
using namespace std;
bool ar[512];
int main(){
    string k;
    freopen("C:\\Users\\Admin\\Desktop\\sub\\laptop\\BMHack\\for2000.txt", "r", stdin);
    while(getline(cin, k))
        for(char i: k) ar[i] = 1;
    for(int i = 0; i < 512; ++i) if(ar[i]) cout << (char) i;
}