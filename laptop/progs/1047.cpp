#include<iostream>
#include<vector>
using namespace std;
int n,m,t,tem,ans;
vector<int> pol;
vector<pair<int,int> > area;
bool ck(int cur,int an){
	while(cur%2==an%2){
		cur/=2;
		an/=2;
	}
	if(cur%2==1) return true;
	return false;
}
int main(){
	//freopen("file.txt","w",stdout);
	int cas=1;
	while(cin >> n >> m && (n||m) ){ //Poles , Builds
		int mx=-1;
		area.clear(); pol.clear();
		for(int i=0;i<n;i++){
			cin >> tem;
			pol.push_back(tem);
		}
		cin >> t;
		for(int i=0;i<t;i++){
			int k,bt=0; cin >> k;
			for(int j=0;j<k;j++){
				cin >> tem; tem--;
				bt+= (1 << tem);
			}
			cin >> tem;
			area.push_back(make_pair(bt,tem));
		}
		for(int i=1;i<(1<<n);i++){ //Case Gen
			int cnt=0,ret=0;
			for(int j=0;j<n;j++){
				if(i&(1 << j)){
					cnt++;
					ret+=pol[j];
				}
			}
			if(cnt!=m) continue;
			for(auto j:area){
				int cut=j.first&i,dig=0;
				while(cut){
					if(cut%2){
						cut--; dig++;
					}
					cut/=2;
				}
				//cout << dig << " ";
				if(dig) ret-=((dig-1)*j.second);
			}
			if(ret>mx||(ret==mx&&ck(i,ans))){ // Case Check***
				mx=ret;
				ans=i;
			}
			//cout << endl;
			//for(int x=0;x<n;x++) if(i&(1 << x))cout << " " << x+1; cout << endl;
		}
		cout << "Case Number  " << cas++ << endl << "Number of Customers: " << mx << endl << "Locations recommended:";
		for(int x=0;x<n;x++) if(ans&(1 << x))cout << " " << x+1;
		cout << endl << endl;
	}
	//fclose(stdout);
}
