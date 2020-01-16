#include<iostream>  
#include<set>  
#include<map>  
using namespace std;  
int main(){  
    double ct=0;  
    int n; cin >> n;  
    set<string> s; // Used  
    map<string,int> m; // Amount  
    s.clear(); m.clear();  
    while(n--){ // Input  
        string tem; cin >> tem;  
        if(!s.insert(tem).second) ct+=m[tem]; // Self-Count  
        m[tem]++; // Amount-Count  
    }  
    for(string i:s){ // Counts  
        for(string j:s){  
            if(i==j) break;  
            for(int k=0;k<3;k++) if(i[k]==j[k]){  
                ct=ct+m[i]*m[j];  
                break;  
            }  
        }  
    }  
    cout << ct;  
}
