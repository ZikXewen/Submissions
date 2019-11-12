#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string pat="UUDDLRLRBAS",txt;
int lps[105],X=12;
void computeLPSArray() {
 	int len=0;
    lps[0]=0; 
	int i=1; 
    while (i<pat.length()) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len != 0) len = lps[len - 1]; 
    	else lps[i++]=0; 
    }
}
bool KMPSearch(int X) {
    int i=0,j=0;
    while (i < txt.length()) { 
        if (pat[j] == txt[i]) { 
            i++; j++; 
        }
        if (j==X) {if(i==txt.length()) return true; j=lps[j-1];}
        else if (i < txt.length() && pat[j] != txt[i]) { 
            if (j != 0) j=lps[j-1]; 
            else i++; 
        } 
    }
	return false; 
}
int main(){
	cin >> txt; computeLPSArray();
	while(--X) if(KMPSearch(X)) break;
	for(;X<=pat.length();X++) printf("%c",pat[X]);
}
