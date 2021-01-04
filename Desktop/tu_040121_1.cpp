#include <cstdio>
int a[2][2], b[2][2];
int main(){
    printf("Enter Matrix A\n");
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j){
        printf("Row %d, Collumn %d : ", i + 1, j + 1);
        scanf("%d", &a[i][j]);
    }
    printf("\nEnter Matrix B\n");
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j){
        printf("Row %d, Collumn %d : ", i + 1, j + 1);
        scanf("%d", &b[i][j]);
    }
    printf("\nSum Matrix\n");
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j)
        printf("Row %d, Collumn %d : %d\n", i + 1, j + 1, a[i][j] + b[i][j]);
}