#include <bits/stdc++.h>
using namespace std;
int N, M;
struct node{
    node *cd[2] = {}, *pa, *ppa;
    bool dir() {return pa -> cd[1] == this;}
    void rot() {
        bool d = dir(); const auto tpa = pa;
        if(tpa -> pa) tpa -> pa -> add(tpa -> dir(), this);
        else pa = nullptr;
        tpa -> add(d, cd[!d]); 
        add(!d, tpa);
        ppa = tpa -> ppa;
    }
    void spy() {
        for(; pa; rot()) if(pa -> pa) 
            (dir() == pa -> dir()? pa : this) -> rot();
    }
    void add(bool sd, node *nw){
        if(nw) nw -> pa = this;
        cd[sd] = nw;
    }
    node() = default;
} *tr[100005];

void del(node *u){
    if(!(u -> cd[1])) return;
    u -> cd[1] -> ppa = u;
    u -> cd[1] -> pa = nullptr;
}
node* ac(node *u){
    u -> spy();
    del(u);
    u -> cd[1] = nullptr;
    node *p = u;
    while(u -> ppa){
        p = u -> ppa;
        p -> spy();
        del(p);
        p -> add(1, u);
        u -> ppa = nullptr;
        u -> spy();
    }
    return p;
}
node* rt(node *u){
    ac(u);
    for(; u -> cd[0]; u = u -> cd[0]);
    ac(u);
    return u;
}
void cut(node *u){
    ac(u);
    u -> cd[0] -> pa = nullptr;
    u -> cd[0] = nullptr;
}
void link(node *u, node *v){ //child, parent
    ac(u); ac(v);
    u -> add(0, v);
}
bool que(node *u, node *v){
    return rt(u) == rt(v);
}
int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) 
        tr[i] = new node();
    while(M--){
        string str; int u, v;
        cin >> str >> u >> v;
        if(str[0] == 'a') link(tr[min(u, v)], tr[max(u, v)]);
        else if(str[0] == 'r') cut(tr[min(u, v)]);
        else cout << (que(tr[u], tr[v])? "YES\n" : "NO\n");
    }
}