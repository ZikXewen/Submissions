#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
long long getMaxArea(vector<int> &hist,int n){
	stack<int> s; long long mx=0,tp,ar,i=0;
    while (i < n){
        if (s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
		else{
            tp = s.top(); s.pop();
            if(s.empty()) ar=hist[tp]*i;
    	    else ar=hist[tp]*(i-s.top()-1);
        	mx=max(mx,ar);
        }
    }
	while (!s.empty()){
        tp = s.top(); s.pop();
        if(s.empty()) ar=hist[tp]*i;
        else ar=hist[tp]*(i-s.top()-1);
        mx=max(mx,ar);
    }
    return mx;
}
int main(){
    int n,a; vector<int> hist;
    while(scanf("%d",&n)&&n){
    	hist.clear();
	    for(int i=0;i<n;i++){
    		scanf("%d",&a); hist.push_back(a);
		}
    	printf("%lld\n",getMaxArea(hist,n));
	}
}

