#include<iostream>
#include<string>
using namespace std;
int lcs(string X, string Y){
    int m = X.length(), n = Y.length();
    int L[2][n+1]; // Current Row & Previous Row
    bool bi; 
    for (int i=0; i<=m; i++){
		bi=i&1;
        for (int j=0; j<=n; j++){
            if (i == 0 || j == 0) L[bi][j] = X[0]==Y[0];
            else if (X[i] == Y[j-1]) L[bi][j] = L[1-bi][j-1] + 1;
            else L[bi][j] = max(L[1-bi][j], L[bi][j-1]);
        }
    }
    return L[bi][n];
}
int main(){
	string a,b; cin >> a >> b; cout << lcs(a,b);
}
