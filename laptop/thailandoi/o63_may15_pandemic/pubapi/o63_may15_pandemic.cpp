#include <bits/stdc++.h>
#include "pandelib.cpp"
using namespace std;
int dig(int u, int base, int dig){
    return (int)(u / pow(base, dig)) % base;
}
int an, te = 1;
bool mk[100000], res[100000];
int main(){
    int N, K, L;
    pandemic_init(N, K, L);
    vector<int> v[K];

    for(int k = 0; k < 5; ++k) // Dig 0 -> 4
        for(int i = 0; i < N; ++i)
            if((4 * k) + dig(i, 4, k) < 3) // Only 0 1 2
                v[(4 * k) + dig(i, 4, k)].emplace_back(i); 
    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int k = 0; k < 5; ++k) // Dig 5 -> 8
        for(int i = 0; i < N; ++i)
            if((4 * k) + dig(i, 4, 4 + k) < 3)
                v[(4 * k) + dig(i, 4, 4 + k)].emplace_back(i);          
    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int k = 0; k < 5; ++k) // Dig 5 -> 8
        for(int i = 0; i < N; ++i)
            if((4 * k) + dig(i, 4, 4 + k) < 3)
                v[((4 * k) + dig(i, 4, 4 + k) + 1) % 3].emplace_back(i);      // 2 1 0     
    pandemic_assign(v, res);
    for(int i = 0; i < K; ++i) v[i].clear();

    for(int i = 0; i < 28; ++i) pandemic_assign(v, res);

    pandemic_assign(v, res);
    for(int k = 0; k < 5; ++k){
        int fd = -1, lst;
        for(int i = 0; i < 3; ++i)
            if(res[(4 * k) + i]){
                if(!mk[4 * k + i]) fd = i;
                mk[(4 * k) + i] = 1, lst = i;
            }
        an += te * ((fd != -1)? fd : 3);
        te *= 4;
    }
    
    pandemic_assign(v, res);
    for(int k = 0; k < 5; ++k){
        int fd = -1, lst;
        for(int i = 0; i < 3; ++i)
            if(res[(4 * k) + i]){
                if(!mk[4 * k + i]) fd = i;
                mk[(4 * k) + i] = 1, lst = i;
            }
        an += te * ((fd != -1)? fd : lst);
        te *= 4;
    }

    pandemic_assign(v, res); // DIG 7
    
    for(int i = 1; i < 4; ++i){
        for(int j = 0; j < 3; ++j) 
            if(res[4 * i + j] && !mk[4 * i + j]) {an += i * (te >> 2); break;}
    }
    pandemic_answer(an);
}