#include <cstdio>
int in[5];
int main(){
    printf("Enter 5 integers...\n");
    for(int i = 0; i < 5; ++i) scanf("%d", &in[i]);
    printf("\nSquares of each numbers are (respectively)...\n");
    for(int i = 0; i < 5; ++i) printf("%d ", in[i] * in[i]);
}