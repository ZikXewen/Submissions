#include <cstdio>
int ar[6] = {5, 3, 4, 6, 2, 1};
int main(){
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < ar[i]; ++j) printf("?");
        printf("\n");
    }
}
