#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAXN 10001
using namespace std;


vector <int> graph[MAXN], cost[MAXN], edges[MAXN]	;
int L[MAXN], HEAD[MAXN], parent[MAXN], subtree[MAXN], array[MAXN], ST[MAXN << 2], location[MAXN]	;
int pos =0, N;


void build(int pos, int low, int high){
	if(low == high){
		ST[pos] = array[low]	;
		return ;
	} 

	int mid = (low+high) >> 1	;
	build((pos << 1) + 1, low, mid)	;
	build((pos << 1) + 2, mid+1, high)	;

	ST[pos] = ST[(pos << 1) + 1] > ST[(pos << 1) + 2] ? ST[(pos << 1) + 1] : ST[(pos << 1) + 2];
}

int query(int i, int j, int low, int high, int pos){

	if (j < low  || i > high)
		return -1;
	if (i <= low && high <= j){
		return ST[pos]	;
	}
	int mid = (low+high) >> 1	;
	return max(query(i, j, low, mid, (pos << 1) + 1), query(i, j, mid+1, high, (pos << 1) + 2))	;
}

void update(int i, int low, int high, int pos, int value){

	if(i < low || high < i )
		return;

	if (low == high){
		ST[pos] = value;
		return;
	}

	int mid = (low+ high) >> 1 	;
	update(i, low, mid, (pos << 1) + 1, value)	;
	update(i, mid+1, high, (pos << 1) + 2, value)	;

	ST[pos] = ST[(pos << 1) + 1] > ST[(pos << 1) + 2] ? ST[(pos << 1) + 1] : ST[(pos << 1) + 2];
	
}	

void  dfs(int v, int pv){

	parent[v] = pv		;
	L[v] = L[pv] + 1 	;
	subtree[v] = 1	;	

	for (int i = 0; i < graph[v].size(); i++){if (graph[v][i] != pv){
			dfs(graph[v][i], v)	;
			subtree[v] += subtree[graph[v][i]]	;
		}
	}
}

void HLD(int v, int pv, int value){

	if (HEAD[v] == -1)
		HEAD[v] = v 	;
	else
		HEAD[v] = HEAD[pv]	;

	int maxsubtree = 0;
	int Cost;
	int Special = -1;
	location[v] = pos	;
	array[pos++] = value;

	for(int i = 0; i < graph[v].size(); i++){ if (graph[v][i] != pv){

			if (subtree[graph[v][i]] > maxsubtree){

				maxsubtree = subtree[graph[v][i]]	;	
				Cost = cost[v][i]				;
				Special = graph[v][i]				;

			}
		}
	}

	if (Special != -1){
		HLD(Special, v, Cost)	;
		for (int i = 0; i < graph[v].size(); i++)
			if (graph[v][i] != Special && graph[v][i]!= pv){
				HEAD[graph[v][i]] = -1;
				HLD(graph[v][i], v, cost[v][i])	;
			}
	}

}

int LCA(int i, int j){

	while(HEAD[i] != HEAD[j]){

		if (L[HEAD[j]] > L[HEAD[i]])
			j = parent[HEAD[j]]	;
		else
			i = parent[HEAD[i]]	;
	}

	if (L[j] > L[i])
		return i ;
	return j;
}

int query_up(int i, int lca){

	int maximum = 0	;
	while(1){

		if(i == lca) break;

		if (HEAD[i] == HEAD[lca]){

			maximum = max(maximum, query(location[lca]+1, location[i], 0, N-1, 0))	;
			break;
		}

		maximum = max(maximum, query(location[HEAD[i]], location[i], 0, N-1, 0))	;
		i = parent[HEAD[i]]	;
	}

	return maximum;
}

int main(){
	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int t ;
	scanf("%d", &t)	;
	
	char M[10]	;
	int u, v, value, node;
	while(t--){

		scanf("%d", &N)	;
		pos = 0;

		for (int i = 0; i <= MAXN; i++){
			graph[i].clear()	;
			cost[i].clear()		;
			edges[i].clear()	;
		}
		memset(HEAD, 0, sizeof(HEAD))	;
		memset(ST, 0, sizeof(ST))	;
		HEAD[1] = -1	;
		for (int i = 1; i < N; i++){

			scanf("%d %d %d", &u, &v, &value)	;
			graph[v].push_back(u)	;
			graph[u].push_back(v)	;
			cost[v].push_back(value);
			cost[u].push_back(value);
			edges[i].push_back(u)	;
			edges[i].push_back(v)	;

		}

		dfs(1, 0)	;
		HLD(1, 0, 0)		;
		build(0, 0, N-1)	;

		while(1){
			int n, m ;
			scanf("%s", M);
			if (M[0] == 'D')
				break;

			scanf("%d %d", &n, &m)	;
			if (M[0] == 'Q'){

 				int lca = LCA(n, m)	;
				int left = query_up(n, lca)	;
				int right = query_up(m, lca);
				printf("%d\n", max(left, right))	;


			}
			else
				if(M[0] == 'C'){

					if (L[edges[n][0]] > L[edges[n][1]])
						node = edges[n][0];
					else
						node = edges[n][1]	;
					update(location[node], 0, N-1, 0, m)	;
				}
		}

	}
	return 0	;
}