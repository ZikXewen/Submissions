#include"wirelib.cpp"
#include<cstdio>
#include<vector>
using namespace std;
int M=wire_init(),ans[95],ct;
vector<int> st;
void rec(int s,int e,bool t,vector<int> v){
	if(v.empty()) return;
	if(s==e){
		for(int i:v) ans[i]=s; return;
	}
	int m=(s+e+1)>>1;
	vector<int> v1,v2;
	for(int i=s;i<m;i++) cmd_C(i);
	for(int i:v) if(cmd_T(i)!=t) v1.push_back(i); else v2.push_back(i);
	rec(s,m-1,!t,v1);
	rec(m,e,t,v2);
	//ct+=m-s+v.size();
}
int main(){
	for(int i=1;i<=M;i++) st.push_back(i);
	rec(1,M,false,st);
	//printf("%d\n",ct+1);
	cmd_D(ans);
}
