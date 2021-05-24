#include <bits/stdc++.h>
using namespace std;
int N, ans, ar[30];
string str;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> str;
    int len = str.length();
    for(int i = 1; i < (len>>1); ++i){
        int cur = 0;
        for(int j = 0; j < i; ++j) cur += (str[j] != str[j+i]);
        ans += (cur <= N);
        for(int j = 0; j < len-(i<<1); ++j) 
            cur -= (str[j] != str[j+i]),
            cur += (str[j+i] != str[j+(i<<1)]),
            ans += (cur <= N);
    }
    cout << ans;
}