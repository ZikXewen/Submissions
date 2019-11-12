#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<int,int> v[100005];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++) cin >> v[i].first >> v[i].second;
	sort(v,v+N);
	for(int i=0;i<N;i++) cout << v[i].first << ' ' << v[i].second << '\n';
}
