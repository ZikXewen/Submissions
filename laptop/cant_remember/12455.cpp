#include<iostream>
#include<vector>
using namespace std;

int n,ck;
vector<int> a;
bool ans;
void dfs(int st, int sum) {
    int i;
	for(i = st + 1; i <= n; i++) {
        dfs(i, sum + a[i]);
    }
    if(sum==ck) ans=true;
}
int main() {
	int y; cin >> y;
	for(int z=0;z<y;z++){
		a.clear();
		ans=false;
	    cin >> ck >> n;
	    a.push_back(0);
	    for (int i = 0; i < n; i++) {
	        int x;
	        cin >> x;
	        a.push_back(x);
	    }
	    dfs(0, 0);
	    if(ans) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
}
