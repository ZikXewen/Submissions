#include <bits/stdc++.h>
#include "sockslib.h"
#include "sockslib.cpp"
using namespace std;
vector<int> v, ori;
int main() {
 	int n = num() << 1;
 	for(int i = 1; i <= n; i++) ori.emplace_back(i);
 	while(ori.size()) {
 		int l = 1, r = ori.size() - 1;
 		while(l < r){// cout << l << ' ' << r << '\n';
 			int m = ((l + r) >> 1);
 			v.clear();
 			for(int i = l; i <= m; i++) v.emplace_back(ori[i]);
 			int a = ask(v);
 			v.emplace_back(ori.front());
 			if(a == ask(v)) r = m;
 			else l = m + 1;
 		}
 		match(ori[0], ori[l]);
 		ori.erase(ori.begin() + l);
 		ori.erase(ori.begin());
 	}
}
