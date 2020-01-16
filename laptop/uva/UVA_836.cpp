#include<iostream>
#include<cstring>
using namespace std;
char ar[26][26];
int main(){
	//freopen("file.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int cs,tmp,mx,length,width; cin >> cs; while(cs--){
		cin >> ar[0]; int len=strlen(ar[0]); mx=0;
		for(int i=1;i<len;i++) cin >> ar[i];
		for(int i = 0; i < len; i++) { // Mark Starting row
			int sum[26] = {}; // Number of 1's in a certain column
			for(int j = i; j < len; j++) { // Mark Ending row
				for(int k = 0; k < len; k++) { // Mark Column
					sum[k]+=ar[j][k]-'0'; // Add in to check if there was another 1's in the column
					if(k == 0 || tmp != length*width) // Start of the column or it's not a rectangle anymore
						tmp = length = 0;
					tmp += sum[k]; // Add the 1's in that column
					length++; width = j-i+1; // Add up the length& width
					if(tmp==length*width&&mx<tmp) mx=tmp;
				}
			}
		}
		cout << mx << endl; if(cs) cout << endl;
	}
	//fclose(stdout);
}

