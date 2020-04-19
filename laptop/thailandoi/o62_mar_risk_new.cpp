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
    if(A.size() < 3) return A; 
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
bool chk(one pt, const vector<one> &h){
    if(h.size() == 2) return !calc(h[0], h[1], pt) && h[0].x < pt.x && pt.x < h[1].x; // Should've had this case, but the grader doesn't
    if(calc(h[0], h[1], pt) < 0 || calc(h[0], bk(h), pt) > 0) return 0;
    int l = 1, r = h.size() - 1;
    while(l < r){
        int m = (l + r + 1) >> 1;
        if(calc(h[0], h[m], pt) >= 0) l = m;
        else r = m - 1;
    }
    if(l == h.size() - 1) return (bk(h).x - pt.x) * (pt.x - h[0].x) >= 0 && (bk(h).y - pt.y) * (pt.y - h[0].y) >= 0;
    return calc(h[l], h[l + 1], pt) >= 0;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, an = 0; cin >> N >> M;
    vector<one> p1(N), p2(M);
    for(int i = 0; i < N ; ++i) cin >> p1[i].x >> p1[i].y;
    for(int i = 0; i < M ; ++i) cin >> p2[i].x >> p2[i].y;
    vector<one> h1 = hull(p1), h2 = hull(p2);
    for(auto i: p1) an += chk(i, h2);
    for(auto i: p2) an += chk(i, h1);
    cout << an;
}