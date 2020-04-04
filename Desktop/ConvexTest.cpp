#include <bits/stdc++.h> 
#define long long long 
#define pbk(x) ((x)[(x).size() - 2])
#define bk(x) ((x).back())
using namespace std; 
struct one { 
    long x, y; 
    bool operator<(one p){return x < p.x || (x == p.x && y < p.y);}
}; 
long calc(one O, one A, one B){return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);} 
vector<one> hull(vector<one> A){
    if(A.size() < 3) return A; // Not sure 
    sort(A.begin(), A.end()); 
    vector<one> ans; 
    for (int i = 0; i < A.size(); ++i) { 
        while (ans.size() >= 2 && calc(pbk(ans), bk(ans), A[i]) <= 0) ans.pop_back(); 
        ans.emplace_back(A[i]); 
    } 
    for (int i = A.size() - 2, fx = ans.size(); i >= 0; --i) { 
        while (ans.size() > fx && calc(pbk(ans), bk(ans), A[i]) <= 0) ans.pop_back();
        ans.emplace_back(A[i]); 
    }
    ans.pop_back(); return ans; 
}
int main(){
    int N; cin >> N;
    vector<one> pts(N);
    for(int i = 0; i < N ; ++i) cin >> pts[i].x >> pts[i].y;
    vector<one> ans = hull(pts);
    for(auto i: ans) cout << i.x << ' ' << i.y << '\n';
}
/*
7
0 3
2 2
1 1
2 1
3 0
0 0
3 3
*/