#include <bits/stdc++.h>
using namespace std;
int N, T, ans;
priority_queue<int> q;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;
    for(int i = 1, u; i <= N; ++i){
        cin >> u; 
        if(max(u, i) >= T) continue;
        while(q.size() and q.top() >= T - i) q.pop();
        q.push(u - i);
        ans = max(ans, (int)q.size());
    }
    cout << ans;
}