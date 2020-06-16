#include <bits/stdc++.h>
#include "pandelib.cpp"
using namespace std;
int dig(int u, int base, int dig){
    return (int)(u / pow(base, dig)) % base;
}
int an, te = 1;
bool mk[100000];
int main(){
    int N, K, L;
    pandemic_init(N, K, L);
    if(K == 1e5) ;
    vector<int> v[K];
    bool res[K];

    for(int k = 0; k < 5; ++k) // Dig 0 -> 4
        for(int i = 0; i < N; ++i)
            v[(3 * k) + dig(i, 3, k)].emplace_back(i); 

    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int k = 0; k < 5; ++k) // Dig 5 -> 9
        for(int i = 0; i < N; ++i)
            v[(3 * k) + dig(i, 3, 5 + k)].emplace_back(i); 

    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int i = 0; i < N; ++i){ // Dig 10
        int zz = dig(i, 3, 10);
        v[zz * 3].emplace_back(i); 
        v[zz * 3 + 1].emplace_back(i);
        v[zz * 3 + 2].emplace_back(i);
    }
    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int i = 0; i < 27; ++i) pandemic_assign(v, res);

    pandemic_assign(v, res);
    for(int k = 0; k < 5; ++k){
        for(int i = 0; i < 3; ++i)
            if(res[(3 * k) + i]) mk[(3 * k) + i] = 1, an += te * i;
        te *= 3;
        
    }
    
    
    pandemic_assign(v, res);
    for(int k = 0; k < 5; ++k){
        int fd = -1, lst;
        for(int i = 0; i < 3; ++i)
            if(res[(3 * k) + i]){
                if(!mk[3 * k + i]) fd = i;
                mk[(3 * k) + i] = 1, lst = i;
            }
        an += te * ((fd != -1)? fd : lst);
        te *= 3;
    }

    pandemic_assign(v, res);
    for(int i = 3; i < 6; ++i)
        if(res[i] && !mk[i]) {an += te; break;}
    
    pandemic_answer(an);
}