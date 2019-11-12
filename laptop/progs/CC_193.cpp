#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ii pair<int,int>
using namespace std;
vector<ii> v;
int A,B,N,K;
long long mem[100010];
void Input(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> A >> B;
		v.push_back({A,B});
	}
	sort(v.begin(),v.end());
}
int dist(int x,int i){
	return v[x+i].first-v[x].first;
}
int hap(int x,int i){
	return v[x].second+v[x+i].second-dist(x,i);
}
int main(){
	ios_base::sync_with_stdio(false);
	Input();
	if(dist(0,1)<=K) mem[1]=hap(0,1);
	if(dist(0,2)<=K) mem[2]=hap(0,2);
	for(int i=0;i<N;i++){
		mem[i+1]=max(mem[i+1],mem[i]);
		if(dist(i+1,1)<=K) mem[i+2]=max(mem[i+2],mem[i]+hap(i+1,1));
		if(dist(i+1,2)<=K)mem[i+3]=max(mem[i+3],mem[i]+hap(i+1,2));
	}
	cout << mem[N-1];
}
