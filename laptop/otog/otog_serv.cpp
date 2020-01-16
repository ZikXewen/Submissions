#include <bits/stdc++.h>

using namespace std;
const int mxn = 5e2+10 , mxm = 2e3+10 , inf = INT_MAX;

struct walk {
    int v,w;
    friend bool operator < (walk A,walk B) {
        return A.w>B.w;
    }
    bool operator==(const walk &A) const {
        return A.w==w && A.v==v;
    }
};

list<walk> G[mxn];

struct path {
int u,v,w;
} edge[mxm];

int n, dist[mxn];

int dijk(int src,int des) {
    priority_queue<walk> pq;
    fill(dist,dist+n,inf);
    dist[src] = 0;
    pq.push({src, 0});
    while(not pq.empty()) {
        int cur = pq.top().v, w = pq.top().w;
        pq.pop();
        if(cur==des) break;
        for(walk nx : G[cur])
            if(nx.w + w < dist[nx.v]) pq.push({nx.v, dist[nx.v] = nx.w + w});
    }
    return dist[des];
}

void cut (int u, int v, int w){
    G[u].remove({v,w});
    G[v].remove({u,w});
}

void add (int u, int v, int w){
    G[u].push_front({v,w});
    G[v].push_front({u,w});
}

int main() {
    ios::sync_with_stdio(false);
    int m, sum = inf;
    cin >> n >> m;
    for(int i=0, u, v, w; i!=m; ++i) {
        cin >> u >> v >> w;
        add(u,v,w);
        edge[i]={u,v,w};
    }
    for(int i=0, u, v, w; i!=m; ++i) {
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        cut(u,v,w);
        int dis = dijk(u,v);
        if(dis != inf) sum = min(sum, dis+w);
        add(u,v,w);
    }
    cout << sum;
    return 0;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
