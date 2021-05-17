#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> ii;
class com{ public: bool operator() (const ii &u, const ii &v) const { return u.x > v.x or (u.x == v.x and u.y < v.y);}};
gp_hash_table<string, ii> hs;
tree<ii, null_type, com, rb_tree_tag, tree_order_statistics_node_update> st;
int N, vai, ct = -1;
string ty, vas, rv[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> ty;
        if(ty[0] == 'I'){
            cin >> vas;
            auto it = hs.find(vas);
            if(it != hs.end()) cout << "EXISTS " << it->y.y << ' ' << it->y.x << '\n';
            else hs[rv[ct] = vas] = ii(0, ++ct), st.insert(ii(0, ct)), cout << "CREATED " << ct << " 0\n";
        } else if(ty[0] == 'D'){
            cin >> vas;
            auto it = hs.find(vas);
            if(it != hs.end()) cout << "OK " << it->y.y << ' ' << it->y.x << '\n', st.erase(st.find(it -> y)), hs.erase(vas);
            else cout << "BAD REQUEST\n";
        } else if(ty[0] == 'R'){
            cin >> vas >> vai;
            auto it = hs.find(vas);
            if(it != hs.end()) st.erase(st.find(it -> y)), st.insert(ii(it -> y.x += vai, it -> y.y)), cout << "OK " << it->y.y << ' ' << it->y.x << '\n';
            else cout << "BAD REQUEST\n";
        } else {
            cin >> vai;
            if(st.empty()) cout << "EMPTY\n";
            else{ 
                auto it = (vai >= st.size())? --st.end() : st.find_by_order(vai);
                cout << "OK " << rv[it->y] << ' ' << it->y << ' ' << it->x << '\n';
            }
        } 
    }
}