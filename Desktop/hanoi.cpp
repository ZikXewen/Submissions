#include <bits/stdc++.h>
using namespace std;
void rec(int x, int a = 1, int b = 2, int c = 3){
    if(x == 1) {cout << a << ' ' << c << '\n'; return;}
    rec(x - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    rec(x - 1, b, a, c);
}
int main(){
    int N;
    cin >> N;
    rec(N);
}