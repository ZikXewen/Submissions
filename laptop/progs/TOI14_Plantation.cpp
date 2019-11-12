#include <bits/stdc++.h>
using namespace std;
const int _N = 1e5+5;
class ii{ public:
	int x,y;
	ii(){x=y=0;}
	ii(int xx,int yy){x=xx,y=yy;}
};
bool cmx(const ii &a,const ii &b){return a.x<b.x;}
bool cmy(const ii &a,const ii &b){return a.y<b.y;}
int N,R,D,W;
ii v[_N],v1[_N],v2[_N];
double dist(ii a,ii b){
	return sqrt((double(a.x-b.x)*double(a.x-b.x)) + (double(a.y-b.y)*double(a.y-b.y)));
}
double stpc(ii *stp,int sz,double mn){
	for(int i=0;i<sz;i++) 
		for(int j=i+1;j<sz&&stp[j].y-stp[i].y<mn;j++) 
			mn=min(dist(stp[i],stp[j]),mn);
	return mn;
}
double cp(ii *vx,ii *vy,int sz){ //cout << sz << endl;
	if(sz==1) return 2e9;
	if(sz==2) return dist(vx[0],vx[1]); 
	ii yl[sz], yr[sz], md=vx[sz>>1], stp[sz]; // left,right,mid,strip
	int sst=0; //size of strip
	for(int i=0,il=0,ir=0;i<sz;i++){
		if(vy[i].x<=md.x) yl[il++]=md;
		else yr[ir++]=md;
	}
	double mn=min(cp(vx,yl,sz>>1),cp(vx+(sz>>1),yr,sz-(sz>>1)));
	for(int i=0;i<sz;i++) if(abs(vy[i].x-md.x)<mn) stp[sst++]=vy[i];
	return min(mn,stpc(stp,sst,mn));
}
int main(){
	scanf("%d",&W);
	while(W--){
		scanf("%d%d%d",&N,&R,&D);
		for(int i=0,x,y;i<N;i++) scanf("%d%d",&x,&y), v[i]=v1[i]=v2[i]=ii(x,y);
		sort(v1,v1+N,cmx); 
		sort(v2,v2+N,cmy);
		//cout << cp(v1,v2,N) << endl;
		if(cp(v1,v2,N)>=(R<<1)+D) printf("Y\n");
		else printf("N\n");
	}
}
