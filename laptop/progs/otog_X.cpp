#include<iostream>
#include<vector>
#include<cstring>
#define INF 2e9
using namespace std;
int n,v[15],run[15];
char a;
void Input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<n;j++){
            cin >> a;
            if(a=='w') t++;
            t<<=1;
        }
        v[i]=t>>1;
    }
    //for(int i=0;i<n;i++) cout << v[i] << endl;
}
void Put(int x,int y){
    if(y<0||y>=n) return;
    if(run[x]&(1<<y)) run[x]-=(1<<y);
    else run[x]|=(1<<y);
}
void Push(int x,int y){
	Put(x,y-1);
	Put(x,y);
	Put(x,y+1);
	Put(x+1,y);
}
int Get(){
    int ct=0;
    for(int i=1;i<n;i++){
        int tem=v[i-1]^run[i-1];// cout << tem << endl;
        for(int j=0;j<n;j++){
            if((1<<j)&tem){
                Push(i,j);
                ct++;
            }
        }
    }
    if(v[n-1]==run[n-1]) return ct;
    return INF;
}
int main(){
    int ret=INF,Ex;
    Input();
    for(int j=0;j<(1<<n);j++){ // RUN TOP
    	//ALL BLACK
		Ex=0;
        for(int i=0;i<n;i++) run[i]=0;
        for(int i=0;i<n;i++) if(j&(1<<i)){Push(0,i); Ex++;} // GENERATE TOP
        ret=min(ret,Ex+Get());
        //ALL WHITE
        Ex=0;
		for(int i=0;i<n;i++) run[i]=(1<<n)-1;
		for(int i=0;i<n;i++) if(j&(1<<i)){Push(0,i); Ex++;} // GENERATE TOP
		ret=min(ret,Ex+Get());
    }
	if(ret!=INF) cout << ret;
	else cout << "Impossible";
}
