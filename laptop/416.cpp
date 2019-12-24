#include<cstdio>
#include<vector>
using namespace std;
int led[10]={126,48,109,121,51,91,95,112,127,123};
vector<int> v;
int tn(char *s){
	int r=0;
	for(int i=0;i<7;i++){
		r*=2;
		if(s[i]=='Y') r++;
	}
	return r;
}
bool cker(){
	for(int i=9;i+1>=v.size();i--){
		bool pss=true;
		int mark=0;
		auto x=v.begin();
		for(int ct=0;ct<v.size();ct++){
			if(*(x+ct)&mark){
				pss=false;
				break;
			}
			if(((*(x+ct))|led[i-ct])!=led[i-ct]){
				pss=false;
				break;
			}
			mark+=((*(x+ct))|mark)^(led[i-ct]|mark);
		}
		if(pss) return true;
	}
}
int main(){
	int n;
//	freopen("file.txt","w",stdout);
	while(scanf("%d",&n)==1 && n){
		v.clear(); char in[7];
		for(int i=0;i<n;i++){
			for(int j=0;j<7;j++) scanf(" %c",&in[j]);
			v.push_back(tn(in));
		}
		if(cker()) printf("MIS");
		printf("MATCH\n");
	}
//	fclose(stdout);
}
