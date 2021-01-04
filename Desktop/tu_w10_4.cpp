#include<cstdio>
int N, x[100], mx, mn = 1e9;
int main(){
    printf("Enter Num = ");
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        printf("x[%d] = ", i + 1);
        scanf("%d", &x[i]);
        if(x[i] < mn) mn = x[i];
        if(x[i] > mx) mx = x[i];
    }
    printf("Maximum = %d\n\nMinimum = %d", mx, mn);
}